/*
 * Transformation.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: mbs729
 */

#include "Transformation.h"

#include "LocalGeo.h"
#include "Point.h"
#include "Ray.h"
#include "Vector.h"

Transformation::Transformation(Matrix m) :
    m(m), minvt(m.inverse()) {
}

Point Transformation::operator*(const Point &p) const {
  float arr[4];
  for (int j = 0; j < 4; ++j) {
    float value = 0.0;
    for (int i = 0; i < 4; ++i) {
      value += m[j][i] * p[i];
    }
    arr[j] = value;
  }
  return Point(arr[0], arr[1], arr[2]);
}

Vector Transformation::operator*(const Vector &v) const {
  float arr[4];
  for (int j = 0; j < 4; ++j) {
    float value = 0.0;
    for (int i = 0; i < 4; ++i) {
      value += m[j][i] * v[i];
    }
    arr[j] = value;
  }
  return Vector(arr[0], arr[1], arr[2]);
}

Normal Transformation::operator*(const Normal &n) const {
  float arr[4];
  for (int j = 0; j < 4; ++j) {
    float value = 0.0;
    for (int i = 0; i < 4; ++i) {
      value += minvt[j][i] * n[i];
    }
    arr[j] = value;
  }
  return Normal(arr[0], arr[1], arr[2]);
}

Ray Transformation::operator*(const Ray &r) const {
  return Ray { (*this) * r.pos, (*this) * r.dir, r.t_min, r.t_max };
}

LocalGeo Transformation::operator*(const LocalGeo &lg) const {
  return LocalGeo { (*this) * lg.pos, (*this) * lg.normal };
}
