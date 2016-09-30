/*
 * Normal.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#include "Normal.h"

Normal::Normal() :
  Normal(0, 0, 0) {
}

Normal::Normal(float x, float y, float z) :
    Vector(x, y, z) {
  normalize();
}

Normal::Normal(const Vector &v) :
  Normal(v.x, v.y, v.z) {
}

Normal Normal::operator +(const Vector &v) {
  return Vector::operator+(v).normalize();
}

Normal Normal::operator -(const Vector &v) {
  return Vector::operator-(v).normalize();
}
