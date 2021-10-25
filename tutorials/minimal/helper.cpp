//
// Created by Mallikarjun Swamy on 10/25/21.
//

#include "helper.h"

float genRandomFloat() {
  static std::default_random_engine e(time(NULL));
  static std::uniform_real_distribution<> dis(0, 1);
  return dis(e);
}

Vec3f Vec3f::operator+(const Vec3f& vec) {
  Vec3f ans;
  ans.x = this->x + vec.x;
  ans.y = this->y + vec.y;
  ans.z = this->z + vec.z;
  return ans;
}

Vec3f Vec3f::operator-(const Vec3f& vec) {
  Vec3f ans;
  ans.x = this->x - vec.x;
  ans.y = this->y - vec.y;
  ans.z = this->z - vec.z;
  return ans;
}

Vec3f operator*(Vec3f vec, const float val) {
  Vec3f ans;
  ans.x = vec.x * val;
  ans.y = vec.y * val;
  ans.z = vec.z * val;
  return ans;
}

Vec3f operator*(const float val, Vec3f vec) {
  return vec * val;
}

float norm(Vec3f vec) {
  return vec.norm();
}
float degToRadian(float deg) {
  return 0.0174533f * deg;
}

Vec3f Light::samplePoint() {
  float u = genRandomFloat(), v = genRandomFloat();
  // TODO : consider doing stratified sampling here.
  Vec3f samplePoint = this->point +  u * edge1.tfar * Vec3f(this->edge1.dir_x, this->edge1.dir_y, this->edge1.dir_z) +
      v * edge2.tfar * Vec3f(this->edge2.dir_x, this->edge2.dir_y, this->edge2.dir_z);
  return samplePoint;
}
