/*
 * Sphere.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"
#include "Point.h"

class Sphere: public Shape {
private:
  Point center;
  float radius;

public:
  Sphere(float x, float y, float z, float radius);
  virtual ~Sphere();
  bool intersect(Ray &ray, float *thit, LocalGeo *local) override;
  bool intersectP(Ray &ray) override;
};

#endif /* SPHERE_H_ */
