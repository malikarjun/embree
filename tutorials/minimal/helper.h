//
// Created by Mallikarjun Swamy on 10/25/21.
//

#ifndef EMBREE3_LIGHT_H
#define EMBREE3_LIGHT_H

#include <embree3/rtcore.h>
#include <limits>
#include <random>
#include <string>
#include <math.h>

using std::cos;
using std::sin;
using std::acos;
using std::vector;
using std::string;


float genRandomFloat();

class Vec2f {
public:
  float x,y;
  Vec2f() {}
  Vec2f(float val) : x(val), y(val) {
  }
  Vec2f(float x, float y) : x(x), y(y){
  }

  Vec2f operator+(const Vec2f& vec);

  Vec2f& operator+=(const Vec2f& vec);

  std::string to_string() {
    return std::to_string(this->x) + ", " + std::to_string(this->y);
  }
};

class Vec3f {
public:
  // x is actual visibility, y is unavg visibility, z is total visibility
  // x = y / z
  float x,y,z;
  Vec3f() {}
  Vec3f(float val) {
    this->x = val, this->y = val; this->z = val;
  }
  Vec3f(float x, float y, float z) {
    this->x = x, this->y = y, this->z = z;
  }
  float norm() {
    return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
  }

  float dot(const Vec3f& vec) {
    return this->x*vec.x + this->y*vec.y + this->z*vec.z;
  }

  float dotClamp(const Vec3f& vec) {
    return std::max(dot(vec), 0.0f);
  }

  std::vector<float> vectorF() {
    return std::vector<float> {this->x, this->y, this->z};
  }

  Vec3f operator+(const Vec3f& vec);

  Vec3f& operator+=(const Vec3f& vec);

  Vec3f operator-(const Vec3f& vec);

  Vec3f operator*(const Vec3f& vec);



  std::string to_string() {
    return std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z);
  }
};

float getMaxVal(Vec3f vec);

float getMinVal(Vec3f vec);

Vec3f operator*(Vec3f vec, const float val);

Vec3f operator*(const float val, Vec3f vec);

Vec3f operator/(Vec3f vec, const float val);

Vec3f operator/(const float val, Vec3f vec);

Vec3f cross(Vec3f a, Vec3f b);

float norm(Vec3f vec);

Vec3f normalize(Vec3f vec);

float degToRadian(float deg);
Vec3f reverse(Vec3f vec);
Vec3f scaleColor(Vec3f color);

void setOrigin(RTCRay& ray, Vec3f origin);
Vec3f getOrigin(RTCRay ray);

void setDir(RTCRay& ray, Vec3f dir);
Vec3f getDir(RTCRay ray);

Vec3f getSurfNormal(RTCHit hit);

RTCRay createRay(Vec3f org, Vec3f dir, float tnear = 0.0001, float tfar = std::numeric_limits<float>::infinity());

RTCRayHit createRayHit(Vec3f org, Vec3f dir, float tnear = 0.0001, float tfar = std::numeric_limits<float>::infinity());

RTCRayHitNp* createRayHitNp(Vec3f org, vector<Vec3f> points, float tnear = 0.0001, float tfar = std::numeric_limits<float>::infinity());

void setVal(unsigned int* arr, unsigned int val, int size);

void setVal(float* arr, float val, int size) ;

class Camera {
public:
  Vec3f eye, center, up;
  // fovy should be in radians
  float fovy;
  // image width and height
  float width, height;

  // camera coordinate frame
  Vec3f u, v, w;

  Camera() {};
  Camera(Vec3f eye, Vec3f center, Vec3f up, float fovy) {
    this->eye = eye;
    this->center = center;
    this->up = up;
    this->fovy = degToRadian(fovy);
  }
  void setFovy(float fovy);

  void setUpCameraCoordFrame();
};

class Light {
public:
  Vec3f origin, I, normal, center;
  // sigma is the std dev of the gaussian area light
  float sigma;
  RTCRay edge1, edge2;
  Light(){}
  Light(Vec3f a, Vec3f b, Vec3f c, Vec3f I) {
    this->origin = a;
    setEdge1(a, b);
    setEdge2(a, c);
    this->I = I;
  }
  Light(Vec3f a, RTCRay edge1, RTCRay edge2, Vec3f I) {
    this->origin = a;
    this->edge1 = edge1;
    this->edge2 = edge2;
    this->I = I;
  }

  // sets up the normal and the central location of the area light.
  void init();

  std::vector<Vec3f> samplePoints(bool stratified, int numOfSamples = 9);

  Vec3f samplePoint();

  float strength(Vec3f target);

  void setCenter();
  void setNormal();
  void setEdge1(Vec3f a, Vec3f b);
  void setEdge2(Vec3f a, Vec3f c);

  float area();
};





class Material {
public:
  Vec3f diffuse, specular, ambient;
  string name;
  Material() {}
  Material(string name) {
    this->name = name;
  }
};

vector<Vec3f> sampleOverHemisphere(Vec3f normal, int numOfSamples=9);


class ObjMesh {
public:
  vector<Vec3f> vertex;
  vector<Vec3f> vnormal;
  vector<Vec3f> vertindex;
  vector<Vec3f> vnormindex;
  Material material;
};

Material findMaterialByName(vector<Material> materials, string name);

Vec3f makeColor(Vec3f color);


#endif //EMBREE3_LIGHT_H
