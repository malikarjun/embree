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
RTCScene initializeScene(RTCDevice device, vector<ObjMesh> objects)
{
  RTCScene scene = rtcNewScene(device);

  for(ObjMesh objMesh : objects) {

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
          indices[i*stride + j] = (unsigned)objMesh.vertindex[i][j] - 1;
        }
      }
    }
    rtcCommitGeometry(geom);

    rtcAttachGeometry(scene, geom);
    rtcReleaseGeometry(geom);
  }

  rtcCommitScene(scene);

  return scene;
}

Vec3f computeLight(Vec3f ldirection, Material material, Vec3f surfNormal, Vec3f lightColor) {
  ldirection = normalize(ldirection);
  surfNormal = normalize(surfNormal);
  float nDotL = ldirection.dot(surfNormal);
  Vec3f lambert = material.diffuse * lightColor * max (nDotL, 0.0f);

  return lambert;
}


Vec3f castRay(RTCScene scene, vector<ObjMesh> objects, Light light, RTCRay rtcRay)
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

    int sspp = 1;
    for (int i = 0; i < sspp; ++i) {
      Vec3f light_sample = light.samplePoint();
      RTCRay shadow_ray = createRay(hit_point, light_sample - hit_point, 0.01, numeric_limits<float>::infinity());
      rtcOccluded1(scene, &context, &shadow_ray);
      // if hit is not found, that means the surface is not occluded from light source
      if (shadow_ray.tfar >= 0) {
        Vec3f surfNormal = getSurfNormal(rayhit.hit);
        L = L + computeLight(getDir(shadow_ray), objects[rayhit.hit.geomID].material, surfNormal, light.I);
      }
    }
  }
  return L;
}

RTCRay rayThroughPixel(int i, int j, Camera camera) {
  RTCRay ray;
  setOrigin(ray, camera.eye);
  float aspectRatio = camera.width/camera.height;

  float jrand = genRandomFloat(), irand = genRandomFloat();

  float alpha = aspectRatio * tan(camera.fovy/2)*(j + jrand - camera.width/2)/(camera.width/2);
  float beta = tan(camera.fovy/2)*(i + irand - camera.height/2)/(camera.height/2);
  setDir(ray, normalize(alpha*camera.u + beta*camera.v - camera.w));
  return ray;
}

/* -------------------------------------------------------------------------- */

int main()
{
  /* Initialization. All of this may fail, but we will be notified by
   * our errorFunction. */
  RTCDevice device = initializeDevice();

  vector<string> objFileNames = {
      "data/floor.obj","data/grid1.obj"
  };
  vector<ObjMesh> objects;
  for(auto fileName : objFileNames) {
    objects.push_back(readObjFile((BASE_PATH + fileName).c_str()));
  }

  RTCScene scene = initializeScene(device, objects);
  Camera camera = readCameraFile((BASE_PATH + "data/camera.txt").c_str());
  Light light = readLightFile((BASE_PATH + "data/light.txt").c_str());

  int h = camera.height, w = camera.width;
  BYTE image[h][w*3];

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      RTCRay incray = rayThroughPixel(i, j, camera);

      // shoot multiple rays for anti-aliasing
      Vec3f color = castRay(scene, objects, light, incray);
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

