/*
 * Vector.h
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#ifndef GEOM_VECTOR_H_
#define GEOM_VECTOR_H_

class Vector {
public:
  float x, y, z;

  Vector();
  Vector(float x, float y, float z);

  Vector operator+(const Vector &v);
  Vector operator-(const Vector &v);
  Vector operator*(const float n);
  Vector operator/(const float n);

  Vector normalize();
};

#endif /* GEOM_VECTOR_H_ */
