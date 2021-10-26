// Copyright 2009-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#include <embree3/rtcore.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <FreeImage.h>
#include "readfile.h"


#if defined(_WIN32)
#  include <conio.h>
#  include <windows.h>
#endif

std::string BASE_PATH = "../tutorials/minimal/";

/*
 * A minimal tutorial. 
 *
 * It demonstrates how to intersect a ray with a single triangle. It is
 * meant to get you started as quickly as possible, and does not output
 * an image. 
 *
 * For more complex examples, see the other tutorials.
 *
 * Compile this file using
 *   
 *   gcc -std=c99 \
 *       -I<PATH>/<TO>/<EMBREE>/include \
 *       -o minimal \
 *       minimal.c \
 *       -L<PATH>/<TO>/<EMBREE>/lib \
 *       -lembree3 
 *
 * You should be able to compile this using a C or C++ compiler.
 */

/* 
 * This is only required to make the tutorial compile even when
 * a custom namespace is set.
 */
#if defined(RTC_NAMESPACE_USE)
RTC_NAMESPACE_USE
#endif

/*
 * We will register this error handler with the device in initializeDevice(),
 * so that we are automatically informed on errors.
 * This is extremely helpful for finding bugs in your code, prevents you
 * from having to add explicit error checking to each Embree API call.
 */
void errorFunction(void* userPtr, enum RTCError error, const char* str)
{
  printf("error %d: %s\n", error, str);
}

/*
 * Embree has a notion of devices, which are entities that can run 
 * raytracing kernels.
 * We initialize our device here, and then register the error handler so that 
 * we don't miss any errors.
 *
 * rtcNewDevice() takes a configuration string as an argument. See the API docs
 * for more information.
 *
 * Note that RTCDevice is reference-counted.
 */
RTCDevice initializeDevice()
{
  RTCDevice device = rtcNewDevice(NULL);

  if (!device)
    printf("error %d: cannot create device\n", rtcGetDeviceError(NULL));

  rtcSetDeviceErrorFunction(device, errorFunction, NULL);
  return device;
}

/*
 * Create a scene, which is a collection of geometry objects. Scenes are 
 * what the intersect / occluded functions work on. You can think of a 
 * scene as an acceleration structure, e.g. a bounding-volume hierarchy.
 *
 * Scenes, like devices, are reference-counted.
 */
RTCScene initializeScene(RTCDevice device)
{
  RTCScene scene = rtcNewScene(device);

  /* 
   * Create a triangle mesh geometry, and initialize a single triangle.
   * You can look up geometry types in the API documentation to
   * find out which type expects which buffers.
   *
   * We create buffers directly on the device, but you can also use
   * shared buffers. For shared buffers, special care must be taken
   * to ensure proper alignment and padding. This is described in
   * more detail in the API documentation.
   */
  ObjMesh objMesh = readObjFile(string(BASE_PATH + "data/rectangle.obj").c_str());


  RTCGeometry geom = rtcNewGeometry(device, RTC_GEOMETRY_TYPE_TRIANGLE);
  float* vertices = (float*) rtcSetNewGeometryBuffer(geom,
                                                     RTC_BUFFER_TYPE_VERTEX,
                                                     0,
                                                     RTC_FORMAT_FLOAT3,
                                                     3*sizeof(float),
                                                     objMesh.vertex[0].size()*objMesh.vertex.size()
                                                     );

  unsigned* indices = (unsigned*) rtcSetNewGeometryBuffer(geom,
                                                          RTC_BUFFER_TYPE_INDEX,
                                                          0,
                                                          RTC_FORMAT_UINT3,
                                                          3*sizeof(unsigned),
                                                          objMesh.vertindex[0].size()*objMesh.vertindex.size()
                                                          );

  if (vertices && indices)
  {
    unsigned stride = objMesh.vertex[0].size();
    for (int i = 0; i < objMesh.vertex.size(); ++i) {
      for (int j = 0; j < objMesh.vertex[0].size(); ++j) {
        vertices[i*stride + j] = objMesh.vertex[i][j];
      }
    }
    stride = objMesh.vertindex[0].size();
    for (int i = 0; i < objMesh.vertindex.size(); ++i) {
      for (int j = 0; j < objMesh.vertindex[0].size(); ++j) {
        indices[i*stride + j] = (unsigned)objMesh.vertindex[i][j];
      }
    }

/*    vertices[0] = 0.f; vertices[1] = 0.f; vertices[2] = 0.f;
    vertices[3] = 1.f; vertices[4] = 0.f; vertices[5] = 0.f;
    vertices[6] = 0.f; vertices[7] = 1.f; vertices[8] = 0.f;

    indices[0] = 0; indices[1] = 1; indices[2] = 2;*/
  }

  /*
   * You must commit geometry objects when you are done setting them up,
   * or you will not get any intersections.
   */
  rtcCommitGeometry(geom);

  /*
   * In rtcAttachGeometry(...), the scene takes ownership of the geom
   * by increasing its reference count. This means that we don't have
   * to hold on to the geom handle, and may release it. The geom object
   * will be released automatically when the scene is destroyed.
   *
   * rtcAttachGeometry() returns a geometry ID. We could use this to
   * identify intersected objects later on.
   */
  rtcAttachGeometry(scene, geom);
  rtcReleaseGeometry(geom);

  /*
   * Like geometry objects, scenes must be committed. This lets
   * Embree know that it may start building an acceleration structure.
   */
  rtcCommitScene(scene);

  return scene;
}

Vec3f computeLight(Vec3f ldirection, Vec3f surfNormal, Vec3f lightColor) {
//  cout << " dir before normalization is " << ldirection.to_string() << endl;
  ldirection = normalize(ldirection);
//  cout << " dir after normalization is " << ldirection.to_string() << endl;
  surfNormal = normalize(surfNormal);

  float nDotL = ldirection.dot(surfNormal);
  // TODO : we need to take input from file for diffuse coefficients instead of hardcoding
  Vec3f lambert = Vec3f(1, 1, 1) * lightColor * max (nDotL, 0.0f);
  return lambert;
}


Vec3f castRay(RTCScene scene, Light light, RTCRay rtcRay)
{
  struct RTCIntersectContext context;
  rtcInitIntersectContext(&context);

  struct RTCRayHit rayhit;
  rayhit.ray.org_x = rtcRay.org_x;
  rayhit.ray.org_y = rtcRay.org_y;
  rayhit.ray.org_z = rtcRay.org_z;
  rayhit.ray.dir_x = rtcRay.dir_x;
  rayhit.ray.dir_y = rtcRay.dir_y;
  rayhit.ray.dir_z = rtcRay.dir_z;
  rayhit.ray.tnear = 0;
  rayhit.ray.tfar = std::numeric_limits<float>::infinity();
  rayhit.ray.mask = -1;
  rayhit.ray.flags = 0;
  rayhit.hit.geomID = RTC_INVALID_GEOMETRY_ID;
  rayhit.hit.instID[0] = RTC_INVALID_GEOMETRY_ID;

  rtcIntersect1(scene, &context, &rayhit);

  Vec3f L(0);

  if (rayhit.hit.geomID != RTC_INVALID_GEOMETRY_ID) {
//    cout << "Intersection found for prim id " << rayhit.hit.primID << endl;
    // create a ray to the light source
    Vec3f hit_point = getOrigin(rayhit.ray) + rayhit.ray.tfar * getDir(rayhit.ray);

    int sspp = 10000;
    for (int i = 0; i < sspp; ++i) {
      Vec3f light_sample = light.samplePoint();
      RTCRay shadow_ray = createRay(hit_point, light_sample - hit_point, 0.01);
      rtcOccluded1(scene, &context, &shadow_ray);
      // if hit is not found, that means the surface is not occluded from light source
      if (shadow_ray.tfar >= 0) {
        Vec3f surfNormal = getSurfNormal(rayhit.hit);
        L = L + computeLight(getDir(shadow_ray), surfNormal, light.I);
      }
    }
  }
  return L;
}

RTCRay rayThroughPixel(int i, int j, Camera camera) {
  RTCRay ray;
  setOrigin(ray, camera.eye);
  float aspectRatio = camera.width/camera.height;
  float alpha = aspectRatio * tan(camera.fovy/2)*(j + 0.5 - camera.width/2)/(camera.width/2);
  float beta = tan(camera.fovy/2)*(i + 0.5 - camera.height/2)/(camera.height/2);
  setDir(ray, normalize(alpha*camera.u + beta*camera.v - camera.w));
  return ray;
}

/* -------------------------------------------------------------------------- */

int main()
{
  /* Initialization. All of this may fail, but we will be notified by
   * our errorFunction. */
  RTCDevice device = initializeDevice();

  RTCScene scene = initializeScene(device);
  Camera camera = readCameraFile((BASE_PATH + "data/camera.txt").c_str());
  Light light = readLightFile((BASE_PATH + "data/light.txt").c_str());

  int h = camera.height, w = camera.width;
  BYTE image[h][w*3];

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      RTCRay incray = rayThroughPixel(i, j, camera);
      Vec3f color = castRay(scene, light, incray);
      color = scaleColor(reverse(color));

      // set color in BGR format
      image[i][j*3+0] = color.x;
      image[i][j*3+1] = color.y;
      image[i][j*3+2] = color.z;

    }
  }
  FreeImage_Initialise();
  FIBITMAP *img = FreeImage_ConvertFromRawBits(&(image[0][0]), w, h, w * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);

  if (FreeImage_Save(FIF_PNG, img, (BASE_PATH + "image.png").c_str(), 0)) {
    printf("Image saved successfully!");
  }


  FreeImage_DeInitialise();

  /* Though not strictly necessary in this example, you should
 * always make sure to release resources allocated through Embree. */
  rtcReleaseScene(scene);
  rtcReleaseDevice(device);


  return 0;
}

