/*
 * Normal.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#include "Normal.h"

Normal::Normal(float x, float y, float z): Vector(x, y, z) {
  normalize();
}

Normal Normal::operator +(Vector v) {
  return Vector::operator+(v).normalize();
}

Normal Normal::operator -(Vector v) {
  return Vector::operator-(v).normalize();
}
