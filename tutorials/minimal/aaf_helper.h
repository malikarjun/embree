//
// Created by Mallikarjun Swamy on 11/13/21.
//

#ifndef EMBREE3_AAF_HELPER_H
#define EMBREE3_AAF_HELPER_H


#include "helper.h"

using namespace std;


class AAFParam {
public:
  int height, width;
  vector<vector<Vec3f>> vis;
  vector<vector<float>> slope, spp;

  AAFParam(int h, int w) : height(h), width(w), vis(h, vector<Vec3f>(w)),
  slope(h, vector<float>(w)), spp(h, vector<float>(w)) {
  }

};


#endif //EMBREE3_AAF_HELPER_H
