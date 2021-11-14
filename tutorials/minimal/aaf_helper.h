//
// Created by Mallikarjun Swamy on 11/13/21.
//

#ifndef EMBREE3_AAF_HELPER_H
#define EMBREE3_AAF_HELPER_H


#include "helper.h"

using namespace std;

class Pos {
public:
  int x, y;
  Pos(int x, int y): x(x), y(y) {
  }
};


class AAFParam {
public:
  int height, width;
  vector<vector<Vec3f>> vis, brdf;
  vector<vector<Vec2f>> slope;
  vector<vector<int>> spp;
  vector<vector<float>> projDist;
  vector<vector<bool>> useFilterN, useFilterOcc;
  bool firstPass;
  Light light;
  Camera camera;
  vector<ObjMesh> objects;
  float normalRpp, bruteRpp;



  AAFParam(int h, int w, Light light, Camera camera, vector<ObjMesh> &objects,  float normalRpp, float bruteRpp) :
      height(h), width(w),
      vis(h, vector<Vec3f>(w, Vec3f(0.f))), brdf(h, vector<Vec3f>(w, Vec3f(0.f))),
      slope(h, vector<Vec2f>(w)),
      spp(h, vector<int>(w, (int)(normalRpp*normalRpp))),
      projDist(h, vector<float>(w)),
      useFilterN(h, vector<bool>(w, false)), useFilterOcc(h, vector<bool>(w, false)),
      firstPass(true),
      light(light),
      camera(camera),
      objects(objects),
      normalRpp(normalRpp), bruteRpp(bruteRpp) {
  }

  float computeWxf( float s2, Pos pos);

  int computeSpp( float s1, float s2, float wxf, Pos pos);

};

//vector<vector<Vec3f>>& heatMap(vector<vector<float> > &img);

Vec3f heatMap(float val, float minVal=0, float maxVal=1);


#endif //EMBREE3_AAF_HELPER_H
