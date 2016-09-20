/*
 * Vector.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#include "Vector.h"

#include <math.h>

Vector::Vector(): Vector(0, 0, 0) {}

Vector::Vector(float x, float y, float z): x(x), y(y), z(z) {}

Vector Vector::operator +(Vector v) {
  return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator -(Vector v) {
  return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator *(float n) {
  return Vector(x * n, y * n, z * n);
}

Vector Vector::operator /(float n) {
  return Vector(x / n, y / n, z / n);
}

Vector Vector::normalize() {
  float dividend = sqrt(x*x + y*y + z*z);
  if (dividend == 0) {
    return Vector();
  }
  return Vector(x / dividend, y / dividend, z / dividend);
}
