/*
 * AggregatePrimitive.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "AggregatePrimitive.h"

#include <cstdlib>
#include <limits>

#include "Intersection.h"

AggregatePrimitive::AggregatePrimitive(std::vector<Primitive*> &list) :
    list(list) {
}

AggregatePrimitive::~AggregatePrimitive() {
}

bool AggregatePrimitive::intersect(const Ray &ray, float *thit,
    Intersection *in) {
  float nearestThit = std::numeric_limits<float>::infinity();
  float currThit;
  Intersection currIn;
  Intersection nearestIn;
  bool madeHit = false;
  for (Primitive *prim : list) {
    if (prim->intersect(ray, &currThit, &currIn)) {
      madeHit = true;
      // Pick the closest hit in front of the eye to render.
      // Discount hit at distance 0, because point would be at the eye.
      if (currThit > 0 && currThit < nearestThit) {
        nearestThit = currThit;
        nearestIn = currIn;
      }
    }
  }
  *thit = nearestThit;
  *in = nearestIn;
  return madeHit;
}

bool AggregatePrimitive::intersectP(const Ray &ray) const {
  for (Primitive *prim : list) {
    if (prim->intersectP(ray)) {
      return true;
    }
  }
  return false;
}

void AggregatePrimitive::getBRDF(LocalGeo &local, BRDF *brdf) {
  exit(1);
}
