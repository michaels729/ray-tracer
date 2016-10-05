/*
 * PointLight.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "PointLight.h"

#include "../geo/LocalGeo.h"
#include "../geo/Ray.h"
#include "../geo/Vector.h"

PointLight::PointLight(float x, float y, float z, float r, float g, float b) :
    pos(Point(x, y, z)), color(Color(r, g, b)) {
}

PointLight::~PointLight() {
}

void PointLight::generateLightRay(const LocalGeo &local, Ray *lray,
    Color *lcolor) {
  float offset = 0.0001f;
  lray->pos = Point(pos.x + offset, pos.y + offset, pos.z + offset);
  lray->dir = local.pos - pos;
  *lcolor = color;
}
