/*
 * RayTracer.h
 *
 *  Created on: Sep 29, 2016
 *      Author: mbs729
 */

#ifndef RAYTRACER_H_
#define RAYTRACER_H_
class Color;
class Primitive;
struct Ray;

class RayTracer {
private:
  int maxDepth;
  Primitive &primitive;
  void trace(const Ray &ray, int depth, Color *color);
//  Ray createReflectRay(LocalGeo &lg, Ray &ray);
//  Color shading(LocalGeo *lg, BRDF *brdf, Ray &lray, Color *lcolor);

public:
  RayTracer(int maxDepth, Primitive &primitive);
  virtual ~RayTracer();
  void trace(const Ray &ray, Color *color);
};

#endif /* RAYTRACER_H_ */
