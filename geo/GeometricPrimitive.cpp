/*
 * GeometricPrimitive.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "GeometricPrimitive.h"

#include "../color/BRDF.h"
#include "../color/Material.h"
#include "Intersection.h"
#include "LocalGeo.h"
#include "Ray.h"
#include "Shape.h"

GeometricPrimitive::GeometricPrimitive(Transformation objToWorld,
    Transformation worldToObj, Shape *shape, Material *material) :
    objToWorld(objToWorld), worldToObj(worldToObj), shape(shape), material(
        material) {
}

GeometricPrimitive::~GeometricPrimitive() {
}

bool GeometricPrimitive::intersect(const Ray &ray, float *thit, Intersection *in) {
  Ray oray = worldToObj * ray;
  LocalGeo olocal;
  if (!shape->intersect(oray, thit, &olocal)) {
    return false;
  }
  in->primitive = this;
  in->localGeo = objToWorld * olocal;
  return true;
}

bool GeometricPrimitive::intersectP(const Ray &ray) const {
  Ray oray = worldToObj * ray;
  return shape->intersectP(oray);
}

void GeometricPrimitive::getBRDF(LocalGeo &local, BRDF *brdf) {
  return material->getBRDF(local, brdf);
}
