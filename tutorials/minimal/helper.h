//
// Created by Mallikarjun Swamy on 10/25/21.
//

#ifndef EMBREE3_LIGHT_H
#define EMBREE3_LIGHT_H

#endif //EMBREE3_LIGHT_H
#include <embree3/rtcore.h>
#include <limits>
#include <random>
#include <string>
#include <math.h>

using std::cos;
using std::sin;
using std::acos;


float genRandomFloat();



class Vec3f {
  public:
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

class Camera {
public:
  Vec3f eye, center, up;
  // fovy should be in radians
  float fovy;
  // image width and height TODO: should this be here?
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

    Vec3f strength(Vec3f target);

    void setCenter();
    void setNormal();
    void setEdge1(Vec3f a, Vec3f b);
    void setEdge2(Vec3f a, Vec3f c);

    float area();
};

using std::vector;
using std::string;



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
  // TODO : use a vector of Vec3f instead of vector<vector>
  vector<Vec3f> vertex;
  vector<Vec3f> vnormal;
  vector<Vec3f> vertindex;
  vector<Vec3f> vnormindex;
  Material material;
};

Material findMaterialByName(vector<Material> materials, string name);


