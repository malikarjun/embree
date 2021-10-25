//
// Created by Mallikarjun Swamy on 10/25/21.
//

#ifndef EMBREE3_READFILE_H
#define EMBREE3_READFILE_H

#endif //EMBREE3_READFILE_H
#include <vector>
#include "helper.h"

using namespace std;


class ObjMesh {
public:
  vector<vector<float>> vertex;
  vector<vector<float>> vnormal;
  vector<vector<float >> vertindex;
  vector<vector<float >> vnormindex;
  vector<float> diffuse;
};

ObjMesh readObjFile (const char * filename);

Camera readCameraFile(const char * filename);
