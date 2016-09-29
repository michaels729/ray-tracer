/*
 * Transformation.h
 *
 *  Created on: Sep 21, 2016
 *      Author: mbs729
 */

#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

class Transformation {
public:
  Matrix m, minvt;
  Transformation(Matrix m);

  Point operator*(const Point &p);
  Vector operator*(const Vector &v);
  Normal operator*(const Normal &n);
  Ray operator*(const Ray &r);
  LocalGeo operator*(const LocalGeo &lg);
};

#endif /* TRANSFORMATION_H_ */
