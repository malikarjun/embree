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
#include "aaf_helper.h"


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



void computeBrdf(AAFParam &aafParam, ObjMesh& objMesh, Pos pos, RTCRayHit rayHit, Light light, Vec3f hitPoint) {
  Vec3f toLight = light.center - hitPoint;
  Vec3f surfNormal = getSurfNormal(rayHit.hit);

  Vec3f color(0);
  if (aafParam.firstPass) {
    Vec3f L = normalize(toLight);
    float nDotL = surfNormal.dotClamp(L);
    // TODO : compute specular term along with diffuse term
    color = color + objMesh.material.diffuse * nDotL;
    aafParam.brdf[pos.x][pos.y] = color;
  }
}

void afterIntersection(RTCScene scene, RTCIntersectContext &context, RTCRayHit rayhit, Pos pos,
                       vector<ObjMesh> &objects, AAFParam &aafParam) {

  Light light = aafParam.light;
  int x = pos.x, y = pos.y;
  Vec3f hitPoint = getOrigin(rayhit.ray) + rayhit.ray.tfar * getDir(rayhit.ray);

  ObjMesh obj = objects[rayhit.hit.geomID];
  float distToLight = norm(light.center - hitPoint);
  computeBrdf(aafParam, obj, pos, rayhit, light, hitPoint);
  vector<Vec3f> samplePoints = light.samplePoints(true, aafParam.spp[x][y]);

  float d2min = distToLight, d2max = -1;
  for (Vec3f sample : samplePoints) {
    float strength = light.strength(sample);
    Vec3f sampleDir = normalize(sample - hitPoint);
    Vec3f surfNormal =  getSurfNormal(rayhit.hit);

    if (surfNormal.dot(sampleDir) > 0) {
      aafParam.useFilterN[x][y] = true;
      aafParam.vis[x][y].z += strength;

      RTCRayHit shadowRayHit = createRayHit(hitPoint, sample - hitPoint, 0.001);
      rtcIntersect1(scene, &context, &shadowRayHit);
      float d1 = norm(sample - hitPoint);
      // if the shadow ray is occluded
      if (shadowRayHit.hit.geomID != RTC_INVALID_GEOMETRY_ID || shadowRayHit.ray.tfar < d1) {
        aafParam.useFilterOcc[x][y] = true;
        float dprime = shadowRayHit.ray.tfar;
        d2min = min(d2min, d1 - dprime);
        d2max = max(d2max, d1 - dprime);
        if (dprime < 0.000000001) {
          d2min = d1;
        }
      } else {
        aafParam.vis[x][y].y += strength;
      }
    }
  }
  float s1 = distToLight/d2min - 1, s2 = distToLight/d2max - 1;
  aafParam.slope[x][y].x = s1;
  aafParam.slope[x][y].y = s2;
}

bool debug(int i, int j) {
  return i == 0 && j == 0;
}


void initialSampling(RTCScene scene, Pos pos, AAFParam &aafParam) {
  vector<ObjMesh> objects = aafParam.objects;
  int x = pos.x, y = pos.y;
  struct RTCIntersectContext context;
  rtcInitIntersectContext(&context);

  RTCRay rtcRay = rayThroughPixel(x, y, aafParam.camera);
  RTCRayHit rayhit = createRayHit(getOrigin(rtcRay), getDir(rtcRay));
  rtcIntersect1(scene, &context, &rayhit);

  if (rayhit.hit.geomID == RTC_INVALID_GEOMETRY_ID) {
    // if no surface was hit
    aafParam.vis[x][y] = Vec3f(1, 1, 0);
    aafParam.spp[x][y] = 0;
    aafParam.brdf[x][y].x = -2;
    return;
  }
  aafParam.objId[x][y] = (int) rayhit.hit.geomID;

  afterIntersection(scene, context, rayhit, pos, objects, aafParam);
  float s1 = aafParam.slope[x][y].x, s2 = aafParam.slope[x][y].y;

  float projDist = 2.f / aafParam.height * (rayhit.ray.tfar * tan(M_PI/12.f));
  aafParam.projDist[x][y] = projDist;
  float wxf = aafParam.computeWxf(s2, pos);

  aafParam.vis[x][y].x = 1;
  int theoreticalSpp = 0;
  // if we have shadow rays that were occluded
  if (aafParam.useFilterOcc[x][y]) {
    theoreticalSpp = aafParam.computeSpp(s1, s2, wxf, pos);
  }
  aafParam.spp[x][y] = min(theoreticalSpp, aafParam.bruteRpp * aafParam.bruteRpp);

  if (aafParam.useFilterOcc[x][y] && aafParam.vis[x][y].z > 0.01) {
    // y and z are updated in the afterIntersection fn
    aafParam.vis[x][y].x = aafParam.vis[x][y].y / aafParam.vis[x][y].z;
  }
}

Vec2f slopeMinMax(Vec2f& curSlope, bool& useFilt, int objId, int i, int j, bool firstPass, AAFParam &aafParam) {
  Vec2f output_slope = curSlope;
  bool useFilter = false;
  if (i >= 0 && i < aafParam.height && j >= 0 && j < aafParam.width) {
    Vec2f target_slope;
    int targetId = aafParam.objId[i][j];
    // the following line just ensures that pixels corresponding to diff objects are not considered
    if (targetId != objId)
      return output_slope;
    if (firstPass) {
      target_slope = aafParam.slope[i][j];
      useFilter = aafParam.useFilterOcc[i][j];
    }
    else {
      target_slope = aafParam.slopeFilter1d[i][j];
      useFilter = aafParam.useFilterOcc1d[i][j];
    }
    if (useFilter) {
      output_slope.x = max(curSlope.x, target_slope.x);
      output_slope.y = min(curSlope.y, target_slope.y);
    }
  }
  useFilt = useFilt || useFilter;
  return output_slope;
}

void slopeFilterX(Pos pos, AAFParam &aafParam) {
  int x = pos.x, y = pos.y;
  Vec2f curSlope = aafParam.slope[x][y];
  // if there is a shadow at this pixel location, then set this bool to true
  bool useFilter = aafParam.useFilterOcc[x][y];
  int objId = aafParam.objId[x][y];
  for (int i = -aafParam.pixelRadx; i < aafParam.pixelRadx; i++) {
    curSlope = slopeMinMax(curSlope, useFilter, objId, x + i, y, true, aafParam);
  }
  aafParam.useFilterOcc1d[x][y] = aafParam.useFilterOcc1d[x][y] || useFilter;
  aafParam.slopeFilter1d[x][y] = curSlope;
}

void slopeFilterY(Pos pos, AAFParam &aafParam) {
  int x = pos.x, y = pos.y;
  Vec2f curSlope = aafParam.slopeFilter1d[x][y];

  bool useFilter = aafParam.useFilterOcc1d[x][y];
  int objId = aafParam.objId[x][y];
  for (int i = -aafParam.pixelRady; i < aafParam.pixelRady; i++) {
    curSlope = slopeMinMax(curSlope, useFilter, objId, x, y + i, false, aafParam);
  }
  if (!aafParam.useFilterOcc[x][y]) {
    aafParam.useFilterOcc[x][y] = aafParam.useFilterOcc[x][y] | useFilter;
    aafParam.slope[x][y] = curSlope;
  }
}


void adaptiveSampling(RTCScene scene, Pos pos, AAFParam &aafParam) {
  int x = pos.x, y = pos.y;
  if (aafParam.brdf[x][y].x < -1) {
    return;
  }

  Vec2f curSlope = aafParam.slope[x][y];
  float wxf = aafParam.computeWxf(curSlope.y, pos);
  int targetSpp = aafParam.computeSpp(curSlope.x, curSlope.y, wxf, pos);
  aafParam.spp[x][y] = targetSpp;

  int curSpp = (int) (aafParam.normalRpp * aafParam.normalRpp);
  if (curSpp < targetSpp) {
    targetSpp = min(targetSpp, aafParam.maxRppPass * aafParam.maxRppPass);
    aafParam.spp[x][y] = targetSpp - curSpp;

    struct RTCIntersectContext context;
    rtcInitIntersectContext(&context);

    RTCRay rtcRay = rayThroughPixel(x, y, aafParam.camera);
    RTCRayHit rayhit = createRayHit(getOrigin(rtcRay), getDir(rtcRay));
    rtcIntersect1(scene, &context, &rayhit);

    if (rayhit.hit.geomID == RTC_INVALID_GEOMETRY_ID) {
      return;
    }
    afterIntersection(scene, context, rayhit, pos, aafParam.objects, aafParam);
    aafParam.spp[x][y] = targetSpp;
  }
}


/* -------------------------------------------------------------------------- */
/*

void print2d(int** img) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      cout << img[i][j] << endl;
    }
  }
}

void alloc_mem(int*** img, int h, int w) {
  *img = new int*[h];
  for (int i = 0; i < h; ++i) {
    (*img)[i] = new int [w];
  }
}

int main() {
//  Vec3f pos = Vec3f(-4.5, 16, 8);
//  Vec3f pos1 = Vec3f(1.5, 16, 8);
//  Vec3f pos2 = Vec3f(-4.5, 21.8284, 3.8284);
//  Vec3f axis1 = pos1-pos;
//  Vec3f axis2 = pos2-pos;
//
//  Vec3f cross_prod = cross(axis1,axis2);
//  float _sigma = sqrt(norm(cross_prod)/4.0f);
//  cout << "Light sigma is " << _sigma << endl;
//  return 0;
  int **img;

  int h = 640, w = 480;
  alloc_mem(&img, h, w);

  img[0][0] = 1;
  img[0][1] = 2;
  img[1][0] = 3;
  img[1][1] = 4;

  print2d(img);
}
*/

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


  AAFParam aafParam(h, w, light, camera, objects, 3, 20);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      initialSampling(scene, Pos(i, j), aafParam);
    }
  }

  aafParam.firstPass = false;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      slopeFilterX( Pos(i, j), aafParam);
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      slopeFilterY( Pos(i, j), aafParam);
    }
  }

  bool disableAdaptiveSamp = false;
  float minSpp = numeric_limits<float>::infinity(), maxSpp = -1;
  if (!disableAdaptiveSamp) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        adaptiveSampling(scene, Pos(i, j), aafParam);
        minSpp = min(minSpp, (float)aafParam.spp[i][j]);
        maxSpp = max(maxSpp, (float)aafParam.spp[i][j]);
      }
    }
  }

  bool adapSampleHeatMap = false;
  unsigned char image[h][w*3];
  cout << "Min spp " << minSpp << endl;
  cout << "Max spp " << maxSpp << endl;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      Vec3f color;
      if (adapSampleHeatMap) {
        color = heatMap(aafParam.spp[i][j], minSpp, maxSpp);
        color = makeColor(color);
      } else {
        color = makeColor(aafParam.brdf[i][j] * aafParam.vis[i][j].x);
      }
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

