/*
 * RayTracer.h
 *
 *  Created on: Sep 29, 2016
 *      Author: mbs729
 */

#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include <vector>

#include "light/Light.h"

class Point;

struct BRDF;
class Color;
class Primitive;
struct Ray;

class RayTracer {
private:
  int maxDepth;
  Primitive &primitive;
  std::vector<Light*> lights;
  Point &eyePos;
  void trace(const Ray &ray, int depth, Color *color);
  Color shading(LocalGeo *lg, BRDF *brdf, Ray &lray, Color *lcolor);
//  Ray createReflectRay(LocalGeo &lg, Ray &ray);

public:
  RayTracer(int maxDepth, Primitive &primitive, std::vector<Light*> lights,
      Point &eyePos);
  virtual ~RayTracer();
  void trace(const Ray &ray, Color *color);
};

#endif /* RAYTRACER_H_ */
