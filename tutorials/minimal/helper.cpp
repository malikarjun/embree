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

Vec2f Vec2f::operator+(const Vec2f &vec) {
  Vec2f ans;
  ans.x = this->x + vec.x;
  ans.y = this->y + vec.y;
  return ans;
}

Vec2f& Vec2f::operator+=(const Vec2f &vec) {
  this->x += vec.x;
  this->y += vec.y;
  return *this;
}

Vec3f Vec3f::operator+(const Vec3f& vec) {
  Vec3f ans;
  ans.x = this->x + vec.x;
  ans.y = this->y + vec.y;
  ans.z = this->z + vec.z;
  return ans;
}

Vec3f& Vec3f::operator+=(const Vec3f& vec) {
  this->x += vec.x;
  this->y += vec.y;
  this->z += vec.z;
  return *this;
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

Mat3f Mat3f::operator+(const Mat3f val) {
  Mat3f ans;
  ans.x = this->x + val.x;
  ans.y = this->y + val.y;
  ans.z = this->z + val.z;
  return ans;
}

Mat3f Mat3f::operator*(const float val) {
  Mat3f ans;
  ans.x = this->x * val;
  ans.y = this->y * val;
  ans.z = this->z * val;
  return ans;
}

Mat3f Mat3f::operator*(const Mat3f val) {
  Mat3f ans;
  ans.x.x = this->x.x*val.x.x + this->x.y * val.y.x + this->x.z * val.z.x;
  ans.x.y = this->x.x*val.x.y + this->x.y * val.y.y + this->x.z * val.z.y;
  ans.x.z = this->x.x*val.x.z + this->x.y * val.y.z + this->x.z * val.z.z;

  ans.y.x = this->y.x*val.x.x + this->y.y * val.y.x + this->y.z * val.z.x;
  ans.y.y = this->y.x*val.x.y + this->y.y * val.y.y + this->y.z * val.z.y;
  ans.y.z = this->y.x*val.x.z + this->y.y * val.y.z + this->y.z * val.z.z;

  ans.z.x = this->z.x*val.x.x + this->z.y * val.y.x + this->z.z * val.z.x;
  ans.z.y = this->z.x*val.x.y + this->z.y * val.y.y + this->z.z * val.z.y;
  ans.z.z = this->z.x*val.x.z + this->z.y * val.y.z + this->z.z * val.z.z;

  return ans;
}

Mat3f Mat3f::operator*=(const float val) {
  this->x = this->x * val;
  this->y = this->y * val;
  this->z = this->z * val;
}

Vec3f operator*(Mat3f mat, Vec3f vec) {
  Vec3f val;
  val.x = mat.x.dot(vec);
  val.y = mat.y.dot(vec);
  val.z = mat.z.dot(vec);
  return val;
}

Mat3f rotMat(const float deg, const Vec3f axis) {
  float x = axis.x, y = axis.y, z = axis.z;
  const float rad = degToRadian(deg);

  Mat3f first_term;
  first_term *= cos(rad);

  Mat3f second_term(x*x, x*y, x*z, x*y, y*y, y*z, x*z, y*z, z*z);
  second_term *= (1 - cos(rad));

  Mat3f third_term(0, -z, y, z, 0, -x, -y, x, 0);
  third_term *= sin(rad);

  return first_term + second_term + third_term;
}

Mat3f rotMat(Vec3f rot) {
  rot.x = degToRadian(rot.x);
  rot.y = degToRadian(rot.y);
  rot.z = degToRadian(rot.z);
  Mat3f rz(cos(rot.z), -sin(rot.z), 0, sin(rot.z), cos(rot.z), 0, 0, 0, 1);
  Mat3f ry(cos(rot.y), 0, sin(rot.y), 0, 1, 0, -sin(rot.y), 0 , cos(rot.y));
  Mat3f rx(1, 0, 0, 0, cos(rot.x), -sin(rot.x), 0, sin(rot.x), cos(rot.x));
  return rz * ry * rx;
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
  float val =  (M_PI / 180) *  deg;
  if (val > 2*M_PI)
    val -= 2*M_PI;
  return val;
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

RTCRayHit createRayHit(Vec3f org, Vec3f dir, float tnear, float tfar) {
  RTCRayHit rayHit;
  rayHit.ray = createRay(org, dir, tnear, tfar);
  rayHit.ray.mask = -1;
  rayHit.ray.flags = 0;
  rayHit.hit.geomID = RTC_INVALID_GEOMETRY_ID;
  rayHit.hit.instID[0] = RTC_INVALID_GEOMETRY_ID;

  return rayHit;
}

void setVal(float* arr, float val, int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = val;
  }
}

void setVal(unsigned int* arr, unsigned int val, int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = val;
  }
}

/**
 * Generate stream of rays originating from a single point.
 * @return
 */
RTCRayHitNp* createRayHitNp(Vec3f org, vector<Vec3f> points, float tnear, float tfar) {
  int n = points.size();
  auto *rayHitNp = static_cast<RTCRayHitNp *>(malloc(sizeof(RTCRayHitNp)));

  rayHitNp->ray.org_x = new float[n];
  rayHitNp->ray.org_y = new float[n];
  rayHitNp->ray.org_z = new float[n];

  rayHitNp->ray.dir_x = new float[n];
  rayHitNp->ray.dir_y = new float[n];
  rayHitNp->ray.dir_z = new float[n];

// misc
  rayHitNp->ray.time = new float[n];
  rayHitNp->ray.id = new unsigned int[n];

  rayHitNp->ray.tnear = new float[n];
  for (int i = 0; i < n; ++i) {
    rayHitNp->ray.tnear[i] = 0.001;
  }
  rayHitNp->ray.tfar = new float[n];
  for (int i = 0; i < n; ++i) {
    rayHitNp->ray.tfar[i] = std::numeric_limits<float>::infinity();
  }

  rayHitNp->ray.mask = new unsigned int[n];
  setVal(rayHitNp->ray.mask, -1, n);
  rayHitNp->ray.flags = new unsigned int[n];
  setVal(rayHitNp->ray.flags, 0, n);

  rayHitNp->hit.geomID = new unsigned int[n];
  setVal(rayHitNp->hit.geomID, RTC_INVALID_GEOMETRY_ID, n);

// misc
  rayHitNp->hit.primID = new unsigned int[n];
  rayHitNp->hit.instID[0] = new unsigned int[n];
  rayHitNp->hit.u = new float[n];
  rayHitNp->hit.v = new float[n];
  rayHitNp->hit.Ng_x = new float[n];
  rayHitNp->hit.Ng_y = new float[n];
  rayHitNp->hit.Ng_z = new float[n];


  for (int i = 0; i < n; ++i) {
    rayHitNp->ray.org_x[i] = org.x;
    rayHitNp->ray.org_y[i] = org.y;
    rayHitNp->ray.org_z[i] = org.z;

    Vec3f dir = points[i] - org;
    rayHitNp->ray.dir_x[i] = dir.x;
    rayHitNp->ray.dir_y[i] = dir.y;
    rayHitNp->ray.dir_z[i] = dir.z;
  }
  return rayHitNp;
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
  Vec3f samplePoint = this->origin + u * edge1.tfar * getDir(this->edge1) + v * edge2.tfar * getDir(this->edge2);
  return samplePoint;
}

float Light::strength(Vec3f target) {
  float dist = norm(this->center - target);
  float strength = exp( -0.5 * (dist * dist)/ ( this->sigma *  this->sigma));
  return strength;
}

void Light::init() {
  this->setNormal();
  this->setCenter();
}

std::vector<Vec3f> Light::samplePoints(bool stratified, int numOfSamples) {

  std::vector<Vec3f> samples;

  if (stratified) {
    int rn = sqrt(numOfSamples);
    float e1Step = this->edge1.tfar / rn, e2Step = this->edge2.tfar / rn;

    for(int i = 0; i < rn; ++i) {
      for (int j = 0; j < rn; ++j) {
        Vec3f a = this->origin + i * e1Step * getDir(this->edge1) + j * e2Step * getDir(this->edge2);
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

void Light::setCenter() {
  this->center = this->origin + getDir(this->edge1) * this->edge1.tfar/2 +
      getDir(this->edge2) * this->edge2.tfar/2;
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

Vec3f Light::getB() {
  return this->origin + getDir(this->edge1) * this->edge1.tfar;
}

Vec3f Light::getC() {
  return this->origin + getDir(this->edge2) * this->edge2.tfar;
}

float Light::area() {
  float base = this->edge1.tfar;
  float theta = acos(getDir(this->edge1).dot(getDir(this->edge2)));
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

Vec3f makeColor(Vec3f color) {
  color = Vec3f(pow(color.x, 1/2.2f),  pow(color.y, 1/2.2f), pow(color.z, 1/2.2f));
//  color = scaleColor(reverse(color));
  color = scaleColor(color);
  color = Vec3f(std::min(color.x, 255.f), std::min(color.y, 255.f), std::min(color.z, 255.f));
  return color;
}

