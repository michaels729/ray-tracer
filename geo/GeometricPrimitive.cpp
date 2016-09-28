/*
 * GeometricPrimitive.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "GeometricPrimitive.h"

GeometricPrimitive::GeometricPrimitive() {
  // TODO Auto-generated constructor stub

}

GeometricPrimitive::~GeometricPrimitive() {
}

bool GeometricPrimitive::intersect(Ray &ray, float *thit, Intersection *in) {
  Ray oray = worldToObj * ray;
  LocalGeo olocal;
  if (!shape->intersect(oray, thit, &olocal)) {
    return false;
  }
  in->primitive = this;
  in->localGeo = objToWorld * olocal;
  return true;
}

bool GeometricPrimitive::intersectP(Ray &ray) {
  Ray oray = worldToObj * ray;
  return shape->intersectP(oray);
}

bool GeometricPrimitive::getBRDF(LocalGeo &local, BRDF *brdf) {
  material->getBRDF(local, brdf);
}
