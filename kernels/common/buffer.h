// ======================================================================== //
// Copyright 2009-2020 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "default.h"
#include "device.h"

namespace embree
{
  /*! Implements an API data buffer object. This class may or may not own the data. */
  class Buffer : public RefCount
  {
  public:
    /*! Buffer construction */
    Buffer() 
      : device(nullptr), ptr(nullptr), numBytes(0), shared(false) {}

    /*! Buffer construction */
    Buffer(Device* device, size_t numBytes_in, void* ptr_in = nullptr)
      : device(device), numBytes(numBytes_in)
    {
      device->refInc();
      
      if (ptr_in)
      {
        shared = true;
        ptr = (char*)ptr_in;
      }
      else
      {
        shared = false;
        alloc();
      }
    }
    
    /*! Buffer destruction */
    ~Buffer() {
      free();
      device->refDec();
    }
    
    /*! this class is not copyable */
  private:
    Buffer(const Buffer& other) DELETED; // do not implement
    Buffer& operator =(const Buffer& other) DELETED; // do not implement
    
  public:
    /* inits and allocates the buffer */
    void create(Device* device_in, size_t numBytes_in)
    {
      init(device_in, numBytes_in);
      alloc();
    }
    
    /* inits the buffer */
    void init(Device* device_in, size_t numBytes_in)
    {
      free();
      device = device_in;
      ptr = nullptr;
      numBytes = numBytes_in;
      shared = false;
    }

    /*! sets shared buffer */
    void set(Device* device_in, void* ptr_in, size_t numBytes_in)
    {
      free();
      device = device_in;
      ptr = (char*)ptr_in;
      if (numBytes_in != (size_t)-1)
        numBytes = numBytes_in;
      shared = true;
    }
    
    /*! allocated buffer */
    void alloc()
    {
      if (device)
        device->memoryMonitor(this->bytes(), false);
      size_t b = (this->bytes()+15) & ssize_t(-16);
      ptr = (char*)alignedMalloc(b,16);
    }
    
    /*! frees the buffer */
    void free()
    {
      if (shared) return;
      alignedFree(ptr); 
      if (device)
        device->memoryMonitor(-ssize_t(this->bytes()), true);
      ptr = nullptr;
    }
    
    /*! gets buffer pointer */
    void* data()
    {
      /* report error if buffer is not existing */
      if (!device)
        throw_RTCError(RTC_ERROR_INVALID_ARGUMENT, "invalid buffer specified");
      
      /* return buffer */
      return ptr;
    }

    /*! returns pointer to first element */
    __forceinline char* getPtr() const {
      return ptr;
    }

    /*! returns the number of bytes of the buffer */
    __forceinline size_t bytes() const { 
      return numBytes;
    }
    
    /*! returns true of the buffer is not empty */
    __forceinline operator bool() const { 
      return ptr; 
    }

  public:
    Device* device;  //!< device to report memory usage to
    char* ptr;       //!< pointer to buffer data
    size_t numBytes; //!< number of bytes in the buffer
    bool shared;     //!< set if memory is shared with application
  };

  /*! An untyped contiguous range of a buffer. This class does not own the buffer content. */
  class RawBufferView
  {
  public:
    /*! Buffer construction */
    RawBufferView()
      : ptr_ofs(nullptr), stride(0), num(0), format(RTC_FORMAT_UNDEFINED), modified(true), userData(0) {}

  public:
    /*! sets the buffer view */
    void set(const Ref<Buffer>& buffer_in, size_t offset_in, size_t stride_in, size_t num_in, RTCFormat format_in)
    {
      if ((offset_in + stride_in * num_in) > (stride_in * buffer_in->numBytes))
        throw_RTCError(RTC_ERROR_INVALID_ARGUMENT, "buffer range out of bounds");

      ptr_ofs = buffer_in->ptr + offset_in;
      stride = stride_in;
      num = num_in;
      format = format_in;
      modified = true;
      buffer = buffer_in;
    }

    /*! returns pointer to the first element */
    __forceinline char* getPtr() const {
      return ptr_ofs;
    }

    /*! returns pointer to the i'th element */
    __forceinline char* getPtr(size_t i) const
    {
      assert(i<num);
      return ptr_ofs + i*stride;
    }

    /*! returns the number of elements of the buffer */
    __forceinline size_t size() const { 
      return num; 
    }

    /*! returns the number of bytes of the buffer */
    __forceinline size_t bytes() const { 
      return num*stride; 
    }
    
    /*! returns the buffer stride */
    __forceinline unsigned getStride() const
    {
      assert(stride <= unsigned(inf));
      return unsigned(stride);
    }

    /*! return the buffer format */
    __forceinline RTCFormat getFormat() const {
      return format;
    }

    /*! mark buffer as modified or unmodified */
    __forceinline void setModified(bool b) {
      modified = b;
    }

    /*! mark buffer as modified or unmodified */
    __forceinline bool isModified() const {
      return modified;
    }

    /*! returns true of the buffer is not empty */
    __forceinline operator bool() const { 
      return ptr_ofs; 
    }

    /*! checks padding to 16 byte check, fails hard */
    __forceinline void checkPadding16() const
    {
      if (ptr_ofs && num)
        volatile int MAYBE_UNUSED w = *((int*)getPtr(size()-1)+3); // FIXME: is failing hard avoidable?
    }

  public:
    char* ptr_ofs;      //!< base pointer plus offset
    size_t stride;      //!< stride of the buffer in bytes
    size_t num;         //!< number of elements in the buffer
    RTCFormat format;   //!< format of the buffer
    bool modified;      //!< true if the buffer got modified
    int userData;       //!< special data
    Ref<Buffer> buffer; //!< reference to the parent buffer
  };

  /*! A typed contiguous range of a buffer. This class does not own the buffer content. */
  template<typename T>
  class BufferView : public RawBufferView
  {
  public:
    typedef T value_type;

    /*! access to the ith element of the buffer */
    __forceinline       T& operator [](size_t i)       { assert(i<num); return *(T*)(ptr_ofs + i*stride); }
    __forceinline const T& operator [](size_t i) const { assert(i<num); return *(T*)(ptr_ofs + i*stride); }
  };

  template<>
  class BufferView<Vec3fa> : public RawBufferView
  {
  public:
    typedef Vec3fa value_type;

    /*! access to the ith element of the buffer */
    __forceinline const Vec3fa operator [](size_t i) const
    {
      assert(i<num);
      return Vec3fa(vfloat4::loadu((float*)(ptr_ofs + i*stride)));
    }
    
    /*! writes the i'th element */
    __forceinline void store(size_t i, const Vec3fa& v)
    {
      assert(i<num);
      vfloat4::storeu((float*)(ptr_ofs + i*stride), (vfloat4)v);
    }
  };
}
