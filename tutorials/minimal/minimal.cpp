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
                                                       3*objMesh.vertex.size()*objMesh.vertex.size()
    );

    unsigned* indices = (unsigned*) rtcSetNewGeometryBuffer(geom,
                                                            RTC_BUFFER_TYPE_INDEX,
                                                            0,
                                                            RTC_FORMAT_UINT3,
                                                            3*sizeof(unsigned),
                                                            3*objMesh.vertindex.size()*objMesh.vertindex.size()
    );

    if (vertices && indices)
    {
      unsigned stride = 3;
      for (int i = 0; i < objMesh.vertex.size(); ++i) {
        for (int j = 0; j < objMesh.vertex[i].vectorF().size(); ++j) {
          vertices[i*stride + j] = objMesh.vertex[i].vectorF()[j];
        }
      }

      for (int i = 0; i < objMesh.vertindex.size(); ++i) {
        for (int j = 0; j < objMesh.vertindex[i].vectorF().size(); ++j) {
          indices[i*stride + j] = (unsigned) objMesh.vertindex[i].vectorF()[j] - 1;
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

Vec3f computeLight(RTCRayHit rayHit, Light light, ObjMesh& objMesh, Vec3f lightLoc, Vec3f srayDir) {
  Vec3f lambert;
  Vec3f surfNormal = getSurfNormal(rayHit.hit);
  Vec3f material = objMesh.material.diffuse / M_PI;
  Vec3f lightI = light.strength(lightLoc);

  Vec3f lightNormal = normalize(light.normal);
  Vec3f hitPoint = getOrigin(rayHit.ray) + rayHit.ray.tfar * getDir(rayHit.ray);
  float dist = norm(hitPoint - lightLoc);
  lambert = (lightI * material * surfNormal.dotClamp(srayDir) * lightNormal.dotClamp(srayDir)) / (dist * dist);
  return objMesh.material.ambient + lambert;
}


Vec3f castRay(RTCScene scene, vector<ObjMesh> objects, Light light, RTCRay rtcRay)
{
  struct RTCIntersectContext context;
  rtcInitIntersectContext(&context);

  RTCRayHit rayhit = createRayHit(getOrigin(rtcRay), getDir(rtcRay));
  rtcIntersect1(scene, &context, &rayhit);

  Vec3f L(0);

  if (rayhit.hit.geomID != RTC_INVALID_GEOMETRY_ID) {
    Vec3f hitPoint = getOrigin(rayhit.ray) + rayhit.ray.tfar * getDir(rayhit.ray);
    vector<Vec3f> samplePoints = light.samplePoints(true, 9);

    for (Vec3f lightSample : samplePoints) {
      RTCRayHit shadowRayHit = createRayHit(hitPoint, lightSample - hitPoint, 0.001);
      rtcIntersect1(scene, &context, &shadowRayHit);
      float distToLight = norm(lightSample - hitPoint);
      // light intensity would be computed for the following scenarios
      // 1. if no occlusion found
      // 2. occlusion found but distToOcclusion is greater than distToLight
      if (shadowRayHit.hit.geomID == RTC_INVALID_GEOMETRY_ID || shadowRayHit.ray.tfar >= distToLight) {
        L = L + computeLight(rayhit, light, objects[rayhit.hit.geomID], lightSample, getDir(shadowRayHit.ray));
      }
    }
    L =  L * light.area() / (float) samplePoints.size();
  }
  return L;
}

RTCRay rayThroughPixel(int i, int j, Camera camera) {
  RTCRay ray;
  setOrigin(ray, camera.eye);
  float aspectRatio = camera.width/camera.height;

  float jrand = genRandomFloat(), irand = genRandomFloat();
  // TODO: perform anti aliasing by sampling inside the pixel.
  jrand = 0.5, irand = 0.5;

  float alpha = aspectRatio * tan(camera.fovy/2)*(j + jrand - camera.width/2)/(camera.width/2);
  float beta = tan(camera.fovy/2)*(i + irand - camera.height/2)/(camera.height/2);
  setDir(ray, normalize(alpha*camera.u + beta*camera.v - camera.w));
  ray.tfar = std::numeric_limits<float>::infinity();
  return ray;
}

/* -------------------------------------------------------------------------- */

/*int main() {
  Vec3f pos = Vec3f(-4.5, 16, 8);
  Vec3f pos1 = Vec3f(1.5, 16, 8);
  Vec3f pos2 = Vec3f(-4.5, 21.8284, 3.8284);
  Vec3f axis1 = pos1-pos;
  Vec3f axis2 = pos2-pos;

  Vec3f cross_prod = cross(axis1,axis2);
  float _sigma = sqrt(norm(cross_prod)/4.0f);
  cout << "Light sigma is " << _sigma << endl;
  return 0;
}*/

int main()
{
  /* Initialization. All of this may fail, but we will be notified by
   * our errorFunction. */
  RTCDevice device = initializeDevice();

  bool enableBasic = false;
  string basicPath = enableBasic ? "/basic" : "";

  vector<string> objFileNames;
  if (enableBasic) {
    objFileNames = {"data" + basicPath + "/floor.obj"
//                    , "data" + basicPath + "/light.obj"
    };
  } else {
    objFileNames = {"data/floor.obj", "data/grid1.obj"};
  }

  vector<ObjMesh> objects;
  for(auto fileName : objFileNames) {
    objects.push_back(readObjFile((BASE_PATH + fileName).c_str(),
                                  (BASE_PATH + "data" + basicPath +"/material.mtl").c_str()));
  }

  RTCScene scene = initializeScene(device, objects);
  Camera camera = readCameraFile((BASE_PATH + "data" + basicPath +"/camera.txt").c_str());
  Light light = readLightFile((BASE_PATH + "data" + basicPath +"/light.txt").c_str());

  int h = camera.height, w = camera.width;
  unsigned char image[h][w*3];

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      RTCRay incray = rayThroughPixel(i, j, camera);

      if (j == 320 && i == 100) {
        incray = rayThroughPixel(i, j, camera);
      }

      Vec3f color = castRay(scene, objects, light, incray);
//      color = Vec3f(pow(color.x, 1/2.2f),  pow(color.y, 1/2.2f), pow(color.z, 1/2.2f));
      color = scaleColor(reverse(color));

      // set color in BGR format
      image[i][j*3+0] = min( color.x, 255.f);
      image[i][j*3+1] = min( color.y, 255.f);
      image[i][j*3+2] = min( color.z, 255.f);

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

