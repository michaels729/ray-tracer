/*
 * Triangle.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle: public Shape {
public:
  Triangle();
  virtual ~Triangle();
  bool intersect(Ray &ray, float *thit, LocalGeo *local) override;
  bool intersectP(Ray &ray) override;
};

#endif /* TRIANGLE_H_ */
