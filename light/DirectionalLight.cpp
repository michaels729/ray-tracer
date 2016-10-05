/*
 * DirectionalLight.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "DirectionalLight.h"

#include <limits>

#include "../geo/Point.h"
#include "../geo/Ray.h"

DirectionalLight::DirectionalLight(float x, float y, float z, float r, float g,
    float b) :
    dir(Vector(x, y, z)), color(Color(r, g, b)) {
}

DirectionalLight::~DirectionalLight() {
}

void DirectionalLight::generateLightRay(const LocalGeo &local, Ray *lray,
    Color *lcolor) {
  *lcolor = color;
  // Direction of light is direction *to* the light, so negate it to get the
  // direction *from* the light
  lray->pos = Point(std::numeric_limits<float>::infinity(),
      std::numeric_limits<float>::infinity(),
      std::numeric_limits<float>::infinity());
  lray->dir = -dir;
}
