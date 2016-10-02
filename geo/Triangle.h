/*
 * Triangle.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Point;

class Triangle: public Shape {
private:
  const Point &vertex1, &vertex2, &vertex3;

public:
  Triangle(const Point &vertex1, const Point &vertex2, const Point &vertex3);
  virtual ~Triangle();
  bool intersect(Ray &ray, float *thit, LocalGeo *local) const override;
  bool intersectP(Ray &ray) const override;
};

#endif /* TRIANGLE_H_ */
