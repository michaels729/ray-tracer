/*
 * Triangle.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Triangle.h"

#include "Matrix.h"

Triangle::Triangle(const Point *vertex1, const Point *vertex2,
    const Point *vertex3) :
    vertex1(vertex1), vertex2(vertex2), vertex3(vertex3) {
  Vector edge1 = *vertex2 - *vertex1;
  Vector edge2 = *vertex3 - *vertex1;
  n = edge1.cross(edge2).normalized();
}

Triangle::~Triangle() {
}

bool Triangle::intersect(Ray &ray, float *thit, LocalGeo *local) const {
  Point v1 = *vertex1, v2 = *vertex2, v3 = *vertex3;
  Vector v2MinusV1 = v2 - v1;
  Vector v3MinusV1 = v3 - v1;

  Eigen::Matrix3f A;
  A << v3MinusV1[0], v2MinusV1[0], -ray.dir[0],
       v3MinusV1[1], v2MinusV1[1], -ray.dir[1],
       v3MinusV1[2], v2MinusV1[2], -ray.dir[2];
  Vector b = ray.pos - v1;
  Vector betaGammaHit = A.inverse() * b;

  float beta = betaGammaHit[0], gamma = betaGammaHit[1], hit = betaGammaHit[2];
  if ((beta >= 0 && beta <= 1) && (gamma >= 0 && gamma <= 1)
      && (beta + gamma <= 1) && (hit >= ray.t_min) && (hit <= ray.t_max)) {
    *thit = hit;
    local->pos = ray.pos + (ray.dir * hit);
    local->normal = n;
    return true;
  }
  return false;
}

bool Triangle::intersectP(Ray &ray) const {
  Point v1 = *vertex1, v2 = *vertex2, v3 = *vertex3;
  Vector v2MinusV1 = v2 - v1;
  Vector v3MinusV1 = v3 - v1;

  Eigen::Matrix3f A;
  A << v3MinusV1[0], v2MinusV1[0], -ray.dir[0],
       v3MinusV1[1], v2MinusV1[1], -ray.dir[1],
       v3MinusV1[2], v2MinusV1[2], -ray.dir[2];
  Vector b = ray.pos - v1;
  Vector betaGammaHit = A.inverse() * b;
  float beta = betaGammaHit[0], gamma = betaGammaHit[1], hit = betaGammaHit[2];
  return (beta >= 0 && beta <= 1) && (gamma >= 0 && gamma <= 1)
      && (beta + gamma <= 1) && (hit >= ray.t_min) && (hit <= ray.t_max);
}
