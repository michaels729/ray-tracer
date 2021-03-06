/*
 * Sphere.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "LocalGeo.h"
#include "Point.h"
#include "Ray.h"
#include "Shape.h"

class Sphere: public Shape {
private:
  Point center;
  float radius;

public:
  Sphere(float x, float y, float z, float radius);
  Sphere(Point center, float radius);
  virtual ~Sphere();
  bool intersect(Ray &ray, float *thit, LocalGeo *local) const override;
  bool intersectP(Ray &ray) const override;
};

#endif /* SPHERE_H_ */
