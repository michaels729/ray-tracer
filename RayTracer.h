/*
 * RayTracer.h
 *
 *  Created on: Sep 29, 2016
 *      Author: mbs729
 */

#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include <vector>

#include "color/BRDF.h"
#include "color/Color.h"
#include "geo/Primitive.h"
#include "geo/Ray.h"
#include "light/Light.h"

class RayTracer {
private:
  int maxDepth;
  Primitive &primitive;
  std::vector<Light*> lights;
  void trace(const Ray &ray, int depth, Color *color);
  Color shading(const Ray &eyeRay, LocalGeo *lg, BRDF *brdf, Ray &lray,
      Color *lcolor);
  Ray createReflectRay(LocalGeo &lg, const Ray &ray);

public:
  RayTracer(int maxDepth, Primitive &primitive, std::vector<Light*> lights);
  virtual ~RayTracer();
  void trace(const Ray &ray, Color *color);
};

#endif /* RAYTRACER_H_ */
