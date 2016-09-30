/*
 * RayTracer.h
 *
 *  Created on: Sep 29, 2016
 *      Author: mbs729
 */

#include "color/BRDF.h"
#include "color/Color.h"
#include "geo/Intersection.h"
#include "geo/LocalGeo.h"
#include "geo/Primitive.h"
#include "geo/Ray.h"

#ifndef RAYTRACER_H_
#define RAYTRACER_H_

struct BRDF;
struct Ray;
struct Intersection;
struct LocalGeo;
class Color;
class Primitive;

class RayTracer {
private:
  int maxDepth;
  Primitive &primitive;
//  Ray createReflectRay(LocalGeo &lg, Ray &ray);
//  Color shading(LocalGeo *lg, BRDF *brdf, Ray &lray, Color *lcolor);

public:
  RayTracer(int maxDepth, Primitive &primitive);
  virtual ~RayTracer();
  void trace(const Ray &ray, int depth, Color *color);
};

#endif /* RAYTRACER_H_ */
