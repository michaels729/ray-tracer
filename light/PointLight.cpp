/*
 * PointLight.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "PointLight.h"

#include <cmath>

#include "../geo/Vector.h"

PointLight::PointLight(float x, float y, float z, float r, float g, float b) :
    color(Color(r, g, b)) {
  pos << x, y, z;
}

PointLight::~PointLight() {
}

// Generate a ray starting from the position stored in local geometry to the
// position of the light source.
void PointLight::generateLightRay(const LocalGeo &local, Ray *lray,
    Color *lcolor) {
  float epsilon = 0.001f;

  Vector displacementVec = pos - local.pos;
  Vector direction = displacementVec.normalized();
  // Offset the position to prevent self-intersection.
  Point position = local.pos + direction * epsilon;

  *lcolor = color;
  lray->pos = position;
  lray->dir = direction;
  lray->t_min = 0.0f;
  lray->t_max = sqrt(
      pow(displacementVec[0], 2) + pow(displacementVec[1], 2)
          + pow(displacementVec[2], 2));
}

Point PointLight::getPos() {
  return pos;
}
