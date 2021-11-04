//
// Created by Mallikarjun Swamy on 10/25/21.
//

#include "helper.h"

float genRandomFloat() {
  static std::default_random_engine e(time(NULL));
  static std::uniform_real_distribution<> dis(0, 1);
  return dis(e);
}

float getMaxVal(Vec3f vec) {
  return std::max(vec.x, std::max(vec.y, vec.z));
}

float getMinVal(Vec3f vec) {
  return std::min(vec.x, std::min(vec.y, vec.z));
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
  return normalize(Vec3f(hit.Ng_x, hit.Ng_y, hit.Ng_z));
}

RTCRay createRay(Vec3f org, Vec3f dir, float tnear, float tfar) {
  RTCRay ray;
  setOrigin(ray, org);
  setDir(ray, normalize(dir));
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
  Vec3f samplePoint = this->point +  u * edge1.tfar * getDir(this->edge1) + v * edge2.tfar * getDir(this->edge2);
  return samplePoint;
}

std::vector<Vec3f> Light::samplePoints(bool stratified, int numOfSamples) {

  std::vector<Vec3f> samples;

  if (stratified) {
    int rn = sqrt(numOfSamples);
    float e1Step = this->edge1.tfar / rn, e2Step = this->edge2.tfar / rn;

    for(int i = 0; i < rn; ++i) {
      for (int j = 0; j < rn; ++j) {
        Vec3f a = this->point + i * e1Step * getDir(this->edge1) + j * e2Step * getDir(this->edge2);
        RTCRay edge1 = createRay(a, getDir(this->edge1), 0, e1Step);
        RTCRay edge2 = createRay(a, getDir(this->edge2), 0, e2Step);
        Light localLight(a, edge1, edge2, this->I);
        samples.push_back(localLight.samplePoint());
      }
    }
  } else {
    for (int i = 0; i < numOfSamples; ++i) {
      samples.push_back(samplePoint());
    }
  }
  return samples;
}

void Light::setNormal() {
  this->normal = cross(getDir(this->edge1), getDir(this->edge2));
}

void Light::setEdge1(Vec3f a, Vec3f b) {
  this->edge1 = createRay(a, b - a, 0, norm(b - a));
}

void Light::setEdge2(Vec3f a, Vec3f c) {
  this->edge2 = createRay(a, c - a, 0, norm(c - a));
  setNormal();
}

float Light::area() {
  float base = this->edge1.tfar;
  float theta = acos(normalize(getDir(this->edge1)).dot(normalize(getDir(this->edge2))));
  float height = this->edge2.tfar * sin(theta);
  // area of parallelogram
  return base * height;
}

vector<Vec3f> sampleOverHemisphere(Vec3f normal, int numOfSamples) {
  vector<Vec3f> samples;

  for (int i = 0; i < numOfSamples; ++i) {
    float theta = acos(genRandomFloat());
    float phi = 2*M_PI*genRandomFloat();
    Vec3f s(cos(phi)*sin(theta), sin(phi)* sin(theta), cos(theta));
    Vec3f w = normalize(normal);

    Vec3f a(0, 1, 0);
    // if a and w are close then choose another direction
    if (a.dot(w) > 0.9) {
      a = Vec3f(1, 0, 0);
    }
    Vec3f u = normalize(cross(a, w));
    Vec3f v = cross(w, u);

    samples.push_back(s.x*u + s.y*v + s.z*w);
  }

  return samples;
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

Vec3f barycentricTo3d(RTCHit rtcHit, ObjMesh objMesh) {
  unsigned int primId = rtcHit.primID;
  Vec3f a = objMesh.vertex[primId];
  Vec3f b = objMesh.vertex[primId+1];
  Vec3f c = objMesh.vertex[primId+2];
  return a + rtcHit.u * (b - a) + rtcHit.v * (c - a);
}
