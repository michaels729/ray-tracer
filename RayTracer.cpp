/*
 * RayTracer.cpp
 *
 *  Created on: Sep 29, 2016
 *      Author: mbs729
 */

#include "RayTracer.h"

RayTracer::RayTracer(int maxDepth, Primitive &primitive) :
    maxDepth(maxDepth), primitive(primitive) {
}

RayTracer::~RayTracer() {
}

void RayTracer::trace(const Ray &ray, int depth, Color *color) {
  float thit;
  Intersection in;
  BRDF brdf;
  if (depth >= maxDepth || !primitive.intersect(ray, &thit, &in)) {
    color->setColor(0, 0, 0);
  }
  in.primitive->getBRDF(in.localGeo, &brdf);

//  if (brdf.kr > 0) {
//    Color tempColor;
//    Ray reflectRay = createReflectRay(in.localGeo, ray);
//    trace(reflectRay, depth+1, &tempColor);
//    *color += brdf.kr * tempColor;
//  }
}

//Ray RayTracer::createReflectRay(LocalGeo &lg, Ray &ray) {
//  return Ray();
//}

//Color RayTracer::shading(LocalGeo *lg, BRDF *brdf, Ray &lray, Color *lcolor) {
//  return Color(0, 0, 0);
//}
