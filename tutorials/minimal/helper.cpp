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

Vec3f Vec3f::operator*(const Vec3f& vec) {
  Vec3f ans;
  ans.x = this->x * vec.x;
  ans.y = this->y * vec.y;
  ans.z = this->z * vec.z;
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

Vec3f operator/(Vec3f vec, const float val) {
  Vec3f ans;
  ans.x = vec.x / val;
  ans.y = vec.y / val;
  ans.z = vec.z / val;
  return ans;
}

Vec3f operator/(const float val, Vec3f vec) {
  return vec / val;
}

Vec3f cross(Vec3f a, Vec3f b) {
  return Vec3f(a.y*b.z - a.z*b.y, a.z*b.x - a.z*b.z, a.x*b.y - a.y*b.x);
}

float norm(Vec3f vec) {
  return vec.norm();
}

Vec3f normalize(Vec3f vec) {
  float normval = norm(vec);
  return vec/ normval;
}

float degToRadian(float deg) {
  return 0.0174533f * deg;
}

Vec3f reverse(Vec3f vec) {
  return Vec3f(vec.z, vec.y, vec.x);
}

Vec3f scaleColor(Vec3f color) {
  return color * 255.0f;
}


void setOrigin(RTCRay& ray, Vec3f origin) {
  ray.org_x = origin.x, ray.org_y = origin.y, ray.org_z = origin.z;
}

Vec3f getOrigin(RTCRay ray) {
  return Vec3f(ray.org_x, ray.org_y, ray.org_z);
}

void setDir(RTCRay& ray, Vec3f dir) {
  ray.dir_x = dir.x, ray.dir_y = dir.y, ray.dir_z = dir.z;
}

Vec3f getDir(RTCRay ray) {
  return Vec3f(ray.dir_x, ray.dir_y, ray.dir_z);
}

Vec3f getSurfNormal(RTCHit hit) {
  return Vec3f(hit.Ng_x, hit.Ng_y, hit.Ng_z);
}

RTCRay createRay(Vec3f org, Vec3f dir, float tnear, float tfar) {
  RTCRay ray;
  setOrigin(ray, org);
  setDir(ray, dir);
  ray.tnear = tnear; ray.tfar = tfar;
  return ray;
}

void Camera::setFovy(float fovy) {
  this->fovy = degToRadian(fovy);
}

void Camera::setUpCameraCoordFrame() {
  // setup the camera coordinate frame
  Vec3f a = this->eye - this->center, b = this->up;
  this->w = normalize(a);
  this->u = normalize(cross(b, w));
  this->v = cross(w, u);
}

Vec3f Light::samplePoint() {
  float u = genRandomFloat(), v = genRandomFloat();
  // TODO : consider doing stratified sampling here.
  Vec3f samplePoint = this->point +  u * edge1.tfar * Vec3f(this->edge1.dir_x, this->edge1.dir_y, this->edge1.dir_z) +
      v * edge2.tfar * Vec3f(this->edge2.dir_x, this->edge2.dir_y, this->edge2.dir_z);
  return samplePoint;
}

void Light::setEdge1(Vec3f a, Vec3f b) {
  this->edge1 = createRay(a, b - a, 0, norm(b - a));
}

void Light::setEdge2(Vec3f a, Vec3f c) {
  this->edge2 = createRay(a, c - a, 0, norm(c - a));
}

Material findMaterialByName(vector<Material> materials, string name) {
  Material material;
  for (const auto &item : materials) {
    if (item.name == name) {
      material = item;
      break;
    }
  }
  return material;
}
