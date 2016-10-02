/*
 * Transformation.h
 *
 *  Created on: Sep 21, 2016
 *      Author: mbs729
 */

#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

#include "Matrix.h"
#include "Normal.h"

struct LocalGeo;
class Point;
struct Ray;

class Transformation {
public:
  Matrix m, minvt;
  Transformation(Matrix m);

  Point operator*(const Point &p) const;
  Vector operator*(const Vector &v) const;
  Normal operator*(const Normal &n) const;
  Ray operator*(const Ray &r) const;
  LocalGeo operator*(const LocalGeo &lg) const;
};

#endif /* TRANSFORMATION_H_ */
