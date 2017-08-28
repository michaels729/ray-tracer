/*
 * Transformation.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: mbs729
 */

#include "Transformation.h"

Transformation::Transformation(Matrix m) :
    m(m), minvt(m.inverse().transpose()) {
}

Point Transformation::multiplyPoint(const Point &p) const {
  Eigen::Vector4f pt;
  pt << p[0], p[1], p[2], 1;
  Eigen::Vector4f tmp = m * pt;
  Vector result;
  result << tmp[0], tmp[1], tmp[2];
  return result;
}

Vector Transformation::multiplyVector(const Vector &v) const {
  Eigen::Vector4f vec;
  vec << v[0], v[1], v[2], 0;
  Eigen::Vector4f tmp = m * vec;
  Vector result;
  result << tmp[0], tmp[1], tmp[2];
  return result;
}

Ray Transformation::operator*(const Ray &r) const {
  return Ray {
    multiplyPoint(r.pos),
    multiplyVector(r.dir),
    r.t_min,
    r.t_max
  };
}

LocalGeo Transformation::operator*(const LocalGeo &lg) const {
  return LocalGeo {
    multiplyPoint(lg.pos),
    multiplyVector(lg.normal).normalized()
  };
}
