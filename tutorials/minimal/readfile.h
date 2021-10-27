//
// Created by Mallikarjun Swamy on 10/25/21.
//

#ifndef EMBREE3_READFILE_H
#define EMBREE3_READFILE_H

#endif //EMBREE3_READFILE_H
#include <vector>
#include "helper.h"

extern std::string BASE_PATH;

using namespace std;

vector<Material> readMaterialFile(const char * filename);

ObjMesh readObjFile (const char * filename, const char * matfilename);

Camera readCameraFile(const char * filename);

Light readLightFile(const char * filename);


