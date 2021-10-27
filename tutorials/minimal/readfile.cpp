//
// Created by Mallikarjun Swamy on 10/25/21.
//

#include "readfile.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <deque>
#include <vector>

std::string BASE_PATH = "../tutorials/minimal/";

using namespace std;

// for string delimiter
vector<string> split (string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
    token = s.substr (pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back (token);
  }

  res.push_back (s.substr (pos_start));
  return res;
}

Vec3f vectToVec3f(vector<float> vect) {
  return Vec3f(vect[0], vect[1], vect[2]);
}

vector<float> readValues(stringstream &s)
{
  vector<float> values;
  string val;
  while (s >> val) {
    vector<string> tokens = split(val, "//");
    // TODO :  ignoring the vertex normal indices for now. Will we need them?
    values.push_back(stof(tokens[0]));
  }
  return values;
}

vector<Material> readMaterialFile(const char * filename) {
  vector<Material> materials;
  ifstream in;
  in.open(filename);
  if (in.is_open()) {

    string str, cmd;
    getline (in, str);

    int numOfMats = -1;
    while (in) {
      if (!((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#'))) {
        getline (in, str);
        continue;
      }
      stringstream s(str);
      s >> cmd;
      if (cmd == "newmtl") {
        string name;
        s >> name;
        numOfMats++;
        materials.push_back(Material(name));
      } else if (cmd == "Ka") {
        materials[numOfMats].ambient = vectToVec3f(readValues(s));
      } else if (cmd == "Kd") {
        materials[numOfMats].diffuse = vectToVec3f(readValues(s));
      } else if (cmd == "Ks") {
        materials[numOfMats].specular = vectToVec3f(readValues(s));
      }
      getline (in, str);
    }
  }
  return materials;
}

ObjMesh readObjFile (const char * filename, const char * matfilename) {
  ObjMesh objMesh;

  // read the material file first because each obj file while will have a material associated with it in the
  // material.mtl
  vector<Material> materials = readMaterialFile(matfilename);

  ifstream in;
  in.open(filename);
  // TODO : throw exception if file not found!!
  if (in.is_open()) {

    string str, cmd;
    getline (in, str);
    while (in) {
      if (!((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#'))) {
        getline (in, str);
        continue;
      }
      stringstream s(str);
      s >> cmd;
      if (cmd == "v") {
        objMesh.vertex.push_back(readValues(s));
      } else if (cmd == "vn") {
        objMesh.vnormal.push_back(readValues(s));
      } else if (cmd == "f") {
        objMesh.vertindex.push_back(readValues(s));
      } else if (cmd == "usemtl") {
        string matName;
        s >> matName;
        objMesh.material = findMaterialByName(materials, matName);
      }
      getline (in, str);
    }
  }
  return objMesh;
}

Camera readCameraFile (const char * filename) {
  Camera camera;
  ifstream in;
  in.open(filename);
  if (in.is_open()) {

    string str, cmd;
    getline (in, str);
    while (in) {
      if (!((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#'))) {
        getline (in, str);
        continue;
      }
      stringstream s(str);
      s >> cmd;
      if (cmd == "eye" ) {
        camera.eye = vectToVec3f(readValues(s));
      } else if (cmd == "center") {
        camera.center = vectToVec3f(readValues(s));
      } else if (cmd == "up") {
        camera.up = vectToVec3f(readValues(s));
      } else if (cmd == "fovy") {
        camera.setFovy(readValues(s)[0]);
      } else if (cmd == "size") {
        vector<float> vec = readValues(s);
        camera.width = vec[0], camera.height = vec[1];
      }
      getline (in, str);
    }
  }
  camera.setUpCameraCoordFrame();
  return camera;
}

Light readLightFile (const char * filename) {
  Light light;
  ifstream in;
  in.open(filename);
  if (in.is_open()) {

    string str, cmd;
    getline (in, str);
    while (in) {
      if (!((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#'))) {
        getline (in, str);
        continue;
      }
      stringstream s(str);
      s >> cmd;
      if (cmd == "a" ) {
        light.point = vectToVec3f(readValues(s));
      } else if (cmd == "b" )  {
        light.setEdge1(light.point, vectToVec3f(readValues(s)));
      } else if (cmd == "b" )  {
        light.setEdge2(light.point, vectToVec3f(readValues(s)));
      } else if (cmd == "i" )  {
        light.I = vectToVec3f(readValues(s));
      }
      getline (in, str);
    }
  }
  return light;
}




