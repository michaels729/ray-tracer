/*
 * Point.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#include "Point.h"
#include "Vector.h"

Point::Point(): Point(0, 0, 0) {}

Point::Point(float x, float y, float z): x(x), y(y), z(z) {}

Vector Point::operator +(const Vector &v) {
  return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Point::operator -(const Vector &v) {
  return Vector(x - v.x, y - v.y, z - v.z);
}
