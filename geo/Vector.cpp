/*
 * Vector.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#include "Vector.h"

#include <math.h>
#include <iostream>

using std::cerr;

Vector::Vector() :
    Vector(0, 0, 0) {
}

Vector::Vector(float x, float y, float z) :
    x(x), y(y), z(z) {
}

Vector Vector::operator +(const Vector &v) const {
  return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator -(const Vector &v) const {
  return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator *(const Vector& v) const {
  Vector u = *this;
  return Vector(u.y * v.z - u.z * v.y,
                u.z * v.x - u.x * v.z,
                u.x * v.y - u.y * v.x);
}

Vector Vector::operator *(const float n) const {
  return Vector(x * n, y * n, z * n);
}

Vector Vector::operator /(const float n) const {
  return Vector(x / n, y / n, z / n);
}

const float Vector::operator [](int i) const {
  switch (i) {
  case (0):
    return x;
  case (1):
    return y;
  case (2):
    return z;
  case (3):
    // Graphics convention: Vectors' fourth coordinate is 0
    return 0.0;
  default:
    cerr << "Index out of bounds";
    return -1.0;
  }
}

float Vector::dot(const Vector& v) const {
  return x * v.x + y * v.y + z * v.z;
}

Vector Vector::normalize() {
  float dividend = sqrt(x * x + y * y + z * z);
  if (dividend == 0) {
    return Vector();
  }
  return Vector(x / dividend, y / dividend, z / dividend);
}
