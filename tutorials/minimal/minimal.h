//
// Created by Mallikarjun Swamy on 11/26/21.
//

#ifndef EMBREE3_MINIMAL_H
#define EMBREE3_MINIMAL_H

#include <embree3/rtcore.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <FreeImage.h>
#include "readfile.h"
#include "aaf_helper.h"


class Minimal {
public:
  RTCScene scene;
  RTCDevice device;
  AAFParam aafParam;

  void init();
  void render(unsigned char* pixel);
  void destroy();
};


#endif //EMBREE3_MINIMAL_H
