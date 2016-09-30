/*
 * AggregatePrimitive.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "AggregatePrimitive.h"

#include <cstdlib>

AggregatePrimitive::AggregatePrimitive(std::vector<Primitive*> list) {
}

AggregatePrimitive::~AggregatePrimitive() {
}

bool AggregatePrimitive::intersect(const Ray &ray, float *thit, Intersection *in) {
  for (Primitive *prim : list) {
    if (!prim->intersect(ray, thit, in)) {
      return false;
    }
  }
  return true;
}

bool AggregatePrimitive::intersectP(const Ray &ray) {
  for (Primitive *prim : list) {
    if (!prim->intersectP(ray)) {
      return false;
    }
  }
  return true;
}

bool AggregatePrimitive::getBRDF(LocalGeo &local, BRDF *brdf) {
  exit(1);
}