/*
 * Triangle.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Triangle.h"

#include "LocalGeo.h"
#include "Matrix.h"
#include "Point.h"
#include "Ray.h"

Triangle::Triangle(const Point *vertex1, const Point *vertex2,
    const Point *vertex3) :
    vertex1(vertex1), vertex2(vertex2), vertex3(vertex3),
    n((*vertex2 - *vertex1) * (*vertex3 - *vertex1)) {
}

Triangle::~Triangle() {
}

bool Triangle::intersect(Ray &ray, float *thit, LocalGeo *local) const {
  Point v1 = *vertex1, v2 = *vertex2, v3 = *vertex3;
  Vector v2MinusV1 = v2 - v1;
  Vector v3MinusV1 = v3 - v1;

  Matrix A = Matrix(v3MinusV1.x, v2MinusV1.x, -ray.dir.x,
                    v3MinusV1.y, v2MinusV1.y, -ray.dir.y,
                    v3MinusV1.z, v2MinusV1.z, -ray.dir.z);
  Vector b = ray.pos - v1;
  Vector betaGammaHit = A.inverse() * b;

  float beta = betaGammaHit.x, gamma = betaGammaHit.y, hit = betaGammaHit.z;
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

  Matrix A = Matrix(v3MinusV1.x, v2MinusV1.x, -ray.dir.x,
                    v3MinusV1.y, v2MinusV1.y, -ray.dir.y,
                    v3MinusV1.z, v2MinusV1.z, -ray.dir.z);
  Vector b = ray.pos - v1;
  Vector betaGammaHit = A.inverse() * b;
  float beta = betaGammaHit.x, gamma = betaGammaHit.y, hit = betaGammaHit.z;
  return (beta >= 0 && beta <= 1) && (gamma >= 0 && gamma <= 1)
      && (beta + gamma <= 1) && (hit >= ray.t_min) && (hit <= ray.t_max);
}
