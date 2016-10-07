/*
 * DirectionalLight.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "DirectionalLight.h"

#include <limits>

#include "../geo/LocalGeo.h"
#include "../geo/Ray.h"

DirectionalLight::DirectionalLight(float x, float y, float z, float r, float g,
    float b) :
    dir(Vector(x, y, z)), color(Color(r, g, b)) {
}

DirectionalLight::~DirectionalLight() {
}

// Generate a ray starting from the position stored in local geometry to the
// position of the light source.
void DirectionalLight::generateLightRay(const LocalGeo &local, Ray *lray,
    Color *lcolor) {
  float epsilon = 0.001f;

  *lcolor = color;
  lray->pos = local.pos;
  lray->dir = dir.normalize();
  lray->t_min = epsilon;
  lray->t_max = std::numeric_limits<float>::infinity();
}

Point DirectionalLight::getPos() {
  return Point(std::numeric_limits<float>::infinity(),
      std::numeric_limits<float>::infinity(),
      std::numeric_limits<float>::infinity());
}
