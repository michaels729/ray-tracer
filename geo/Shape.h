/*
 * Shape.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "LocalGeo.h"
#include "Ray.h"

class Shape {
public:
  Shape();
  virtual ~Shape();
  virtual bool intersect(Ray &ray, float *thit, LocalGeo *local) const = 0;
  virtual bool intersectP(Ray &ray) const = 0;
};

#endif /* SHAPE_H_ */
