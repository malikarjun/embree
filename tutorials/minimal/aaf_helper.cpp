//
// Created by Mallikarjun Swamy on 11/13/21.
//

#include "aaf_helper.h"

const float spp_mu = 2;

float AAFParam::computeWxf( float s2, Pos pos ) {
  return min(spp_mu/(this->light.sigma * s2), 1/(this->projDist[pos.x][pos.y]*(1+s2)));
}

int AAFParam::computeSpp( float s1, float s2, float wxf, Pos pos ) {
  float spp_t_1 = (1/(1+s2)+this->projDist[pos.x][pos.y]*wxf);
  float spp_t_2 = (1+this->light.sigma * min(s1*wxf, 1/this->projDist[pos.x][pos.y] * s1/(1+s1) )  );
  float spp = 4*spp_t_1*spp_t_1*spp_t_2*spp_t_2;
  return spp;
}

float gaussFilter(float distsq, float wxf) {
  float sample = distsq*wxf*wxf;
//  if (sample > 0.9999) {
//    return 0.0;
//  }
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
