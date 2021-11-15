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

  std::string to_string() {
    return std::to_string(this->x) + ", " + std::to_string(this->y);
  }
};


class AAFParam {
public:
  int height, width, pixelRadx, pixelRady;
  vector<vector<Vec3f>> vis, brdf, worldLoc, normal;
  vector<vector<Vec2f>> slope, slopeFilter1d;
  vector<vector<int>> spp, objId;
  vector<vector<float>> projDist, visBlur1d;
  vector<vector<bool>> useFilterN, useFilterOcc, useFilterOcc1d;
  bool firstPass, blurOcc;
  Light light;
  Camera camera;
  vector<ObjMesh> objects;
  int normalRpp, bruteRpp, maxRppPass;



  AAFParam(int h, int w, Light light, Camera camera, vector<ObjMesh> &objects,  int normalRpp, int bruteRpp) :
      height(h), width(w), pixelRadx(10), pixelRady(10),
      vis(h, vector<Vec3f>(w, Vec3f(0.f))),brdf(h, vector<Vec3f>(w, Vec3f(0.f))),
      worldLoc(h, vector<Vec3f>(w)), normal(h, vector<Vec3f>(w)),
      slope(h, vector<Vec2f>(w)), slopeFilter1d(h, vector<Vec2f>(w)),
      spp(h, vector<int>(w, (int)(normalRpp*normalRpp))), objId(h, vector<int>(w)),
      projDist(h, vector<float>(w)), visBlur1d(h, vector<float>(w)),
      useFilterN(h, vector<bool>(w, false)), useFilterOcc(h, vector<bool>(w, false)), useFilterOcc1d(h, vector<bool>(w, false)),
      firstPass(true), blurOcc(true),
      light(light),
      camera(camera),
      objects(objects),
      normalRpp(normalRpp), bruteRpp(bruteRpp), maxRppPass(15) {
  }

  float computeWxf( float s2, Pos pos);

  int computeSpp( float s1, float s2, float wxf, Pos pos);

};

float gaussFilter(float distsq, float wxf);

Vec3f heatMap(float val, float minVal=0, float maxVal=1);


#endif //EMBREE3_AAF_HELPER_H
