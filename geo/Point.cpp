/*
 * Point.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#include <iostream>
#include "Point.h"
#include "Vector.h"
using std::cerr;

Point::Point(): Point(0, 0, 0) {}

Point::Point(float x, float y, float z): x(x), y(y), z(z) {}

Point Point::operator +(const Vector &v) {
  return Point(x + v.x, y + v.y, z + v.z);
}

Point Point::operator -(const Vector &v) {
  return Point(x - v.x, y - v.y, z - v.z);
}

Vector Point::operator -(const Point &p) {
  return Vector(x - p.x, y - p.y, z - p.z);
}

const float Point::operator [](int i) const {
  switch (i) {
  case (0):
    return x;
  case (1):
    return y;
  case (2):
    return z;
  case (3):
    // Graphics convention: Points' fourth coordinate is 1
    return 1.0;
  default:
    cerr << "Index out of bounds";
    return -1.0;
  }
}
