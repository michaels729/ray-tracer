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

  Vector operator+(const Vector &v) const;
  Vector operator-() const;
  Vector operator-(const Vector &v) const;
  Vector operator*(const Vector &v) const;
  Vector operator*(const float n) const;
  Vector operator/(const float n) const;
  const float operator[](int i) const;

  float dot(const Vector &v) const;
  Vector normalize() const;
};

#endif /* GEOM_VECTOR_H_ */
