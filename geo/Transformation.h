/*
 * Transformation.h
 *
 *  Created on: Sep 21, 2016
 *      Author: mbs729
 */

#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

#include "LocalGeo.h"
#include "Matrix.h"
#include "Point.h"
#include "Ray.h"
#include "Vector.h"

class Transformation {
public:
  Matrix m, minvt;
  Transformation(Matrix m);

  Point multiplyPoint(const Point &p) const;
  Vector multiplyVector(const Vector &v) const;
  Ray operator*(const Ray &r) const;
  LocalGeo operator*(const LocalGeo &lg) const;
};

#endif /* TRANSFORMATION_H_ */
