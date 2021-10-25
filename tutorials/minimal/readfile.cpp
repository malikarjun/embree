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

ObjMesh readObjFile (const char * filename) {
  ObjMesh objMesh;
  // TODO : at some point we would like to take this as input.
  objMesh.diffuse.push_back(1);objMesh.diffuse.push_back(0);objMesh.diffuse.push_back(0);

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
      if (cmd == "v") {
        objMesh.vertex.push_back(readValues(s));
      } else if (cmd == "vn") {
        objMesh.vnormal.push_back(readValues(s));
      } else if (cmd == "f") {
        objMesh.vertindex.push_back(readValues(s));
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
        camera.fovy = degToRadian(readValues(s)[0]);
      }
      getline (in, str);
    }
  }
  return camera;
}




