/*
 * PointLight.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "PointLight.h"

#include <cmath>

#include "../geo/LocalGeo.h"
#include "../geo/Ray.h"
#include "../geo/Vector.h"

PointLight::PointLight(float x, float y, float z, float r, float g, float b) :
    pos(Point(x, y, z)), color(Color(r, g, b)) {
}

PointLight::~PointLight() {
}

// Generate a ray starting from the position stored in local geometry to the
// position of the light source.
void PointLight::generateLightRay(const LocalGeo &local, Ray *lray,
    Color *lcolor) {
  float epsilon = 0.001f;
  Vector displacementVec = pos - local.pos;

  *lcolor = color;
  lray->pos = local.pos;
  lray->dir = displacementVec.normalize();
  lray->t_min = epsilon;
  lray->t_max = sqrt(
      pow(displacementVec.x, 2) + pow(displacementVec.y, 2)
          + pow(displacementVec.z, 2));
}

Point PointLight::getPos() {
  return pos;
}
