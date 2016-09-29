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
  const float operator[](int i) const;

  float dot(const Vector &v);
  Vector normalize();
};

#endif /* GEOM_VECTOR_H_ */
