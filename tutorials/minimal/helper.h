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

    Vec3f operator+(const Vec3f& vec);

    Vec3f operator-(const Vec3f& vec);

    Vec3f operator*(const Vec3f& vec);

    std::string to_string() {
      return std::to_string(this->x) + " " + std::to_string(this->y) + " " + std::to_string(this->z);
    }
};

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
    Vec3f point, I;
    RTCRay edge1, edge2;
    Light(){}
    Light(Vec3f a, Vec3f b, Vec3f c, Vec3f I) {
      this->point = a;
      this->edge1 = createRay(a, b - a, 0, norm(b - a));
      this->edge2 = createRay(a, c - a, 0, norm(c - a));
      this->I = I;
    }
    Vec3f samplePoint();
    void setEdge1(Vec3f a, Vec3f b);
    void setEdge2(Vec3f a, Vec3f c);
};


