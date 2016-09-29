/*
 * Shape.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Ray;
class LocalGeo;

class Shape {
public:
  Shape();
  virtual ~Shape();
  virtual bool intersect(Ray &ray, float *thit, LocalGeo *local) = 0;
  virtual bool intersectP(Ray &ray) = 0;
};

#endif /* SHAPE_H_ */
