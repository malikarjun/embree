//
// Created by Mallikarjun Swamy on 11/13/21.
//

#include "aaf_helper.h"

const float sppMu = 2;

void AAFParam::reinit() {
  int h = this->height, w = this->width;
  vector<vector<Vec3f> > vis(h, vector<Vec3f>(w, Vec3f(0.f))), brdf(h, vector<Vec3f>(w, Vec3f(0.f))),
      worldLoc(h, vector<Vec3f>(w)), normal(h, vector<Vec3f>(w));
  this->vis = vis;
  this->brdf = brdf;
  this->worldLoc = worldLoc;
  this->normal = normal;

  vector<vector<Vec2f>> slope(h, vector<Vec2f>(w)), slopeFilter1d(h, vector<Vec2f>(w));
  this->slope = slope;
  this->slopeFilter1d = slopeFilter1d;

  vector<vector<int>> spp(h, vector<int>(w, (int)(normalRpp*normalRpp))), objId(h, vector<int>(w));
  this->spp = spp;
  this->objId;

  vector<vector<float>> projDist(h, vector<float>(w)), visBlur1d(h, vector<float>(w)), beta(h, vector<float>(w));
  this->projDist = projDist;
  this->visBlur1d = visBlur1d;
  this->beta = beta;

  vector<vector<bool>>  useFilterN(h, vector<bool>(w, false)), useFilterOcc(h, vector<bool>(w, false)),
  useFilterOcc1d(h, vector<bool>(w, false));
  this->useFilterN = useFilterN;
  this->useFilterOcc = useFilterOcc;
  this->useFilterOcc1d = useFilterOcc1d;

  this->firstPass = true;
  this->blurOcc = true;


}

float AAFParam::computeWxf( float s2, Pos pos ) {
  return min(sppMu / (this->light.sigma * s2), 1 / (this->projDist[pos.x][pos.y] * (1 + s2)));
}

int AAFParam::computeSpp( float s1, float s2, float wxf, Pos pos ) {
  float sppT1 = (1 / (1 + s2) + this->projDist[pos.x][pos.y] * wxf);
  float sppT2 = (1 + this->light.sigma * min(s1 * wxf, 1 / this->projDist[pos.x][pos.y] * s1 / (1 + s1) )  );
  float spp = 4 * sppT1 * sppT1 * sppT2 * sppT2;
  return ceil(spp);
}

float gaussFilter(float distsq, float wxf) {
  float sample = distsq*wxf*wxf;
  if (sample > 0.9999) {
    return 0.0;
  }
  return exp(-3*sample);
}


Vec3f heatMap(float val, float minVal, float maxVal) {
  // normalize the value to bring it between 0 and 1
  val = (val - minVal)/(maxVal - minVal);

  float fraction;
  if (val < 0.0f)
    fraction = -1.0f;
  else if (val > 1.0f)
    fraction = 1.0f;
  else
    fraction = 2.0f * val - 1.0f;

  if (fraction < -0.5f)
    return Vec3f(0.0f, 2*(fraction+1.0f), 1.0f);
  else if (fraction < 0.0f)
    return  Vec3f(0.0f, 1.0f, 1.0f - 2.0f * (fraction + 0.5f));
  else if (fraction < 0.5f)
    return Vec3f(2.0f * fraction, 1.0f, 0.0f);
  else
    return Vec3f(1.0f, 1.0f - 2.0f*(fraction - 0.5f), 0.0f);
}
