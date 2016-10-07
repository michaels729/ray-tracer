/*
 * Sphere.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Sphere.h"

#include <math.h>
#include <algorithm>

#include "LocalGeo.h"
#include "Normal.h"
#include "Ray.h"

Sphere::Sphere(float x, float y, float z, float radius) :
    Sphere(Point(x, y, z), radius) {
}

Sphere::Sphere(Point center, float radius) :
    center(center), radius(radius) {
}

Sphere::~Sphere() {
}

bool Sphere::intersect(Ray &ray, float *thit, LocalGeo *local) const {
  // at^2 + bt + c = 0
  // t = (-b +- sqrt(b*b - 4 * a * c)) / (2 * a)
  // where a = (ray.dir).dot(ray.dir),
  // b = 2 * (ray.dir).dot(ray.pos - center),
  // and c = (ray.pos - center).dot(ray.pos - center)

  float a = (ray.dir).dot(ray.dir);
  Vector positionDiff = ray.pos - center;
  float b = 2 * (ray.dir).dot(positionDiff);
  float c = positionDiff.dot(positionDiff) - radius * radius;
  float discriminant = b * b - 4 * a * c;

  // Failed to intersect. sqrt(discriminant) is imaginary.
  if (discriminant < 0) {
    return false;
  }
  float t0 = (-b + sqrt(discriminant)) / (2 * a);
  float t1 = (-b - sqrt(discriminant)) / (2 * a);
  float hit = -std::numeric_limits<float>::infinity();
  if (t0 > 0 && t1 > 0) {
    // Pick the closer hit
    hit = std::min(t0, t1);
  } else if ((t0 > 0 && t1 < 0) || (t0 < 0 && t1 > 0)) {
    // Hit a point in front of the eye and another point behind the eye,
    // so pick the one in front of they eye
    hit = std::max(t0, t1);
  }
  if (hit < ray.t_min || hit > ray.t_max) {
    return false;
  }
  *thit = hit;
  local->pos = ray.pos + (ray.dir * (*thit));
  local->normal = Normal(local->pos - center);
  return true;
}

bool Sphere::intersectP(Ray &ray) const {
  float a = (ray.dir).dot(ray.dir);
  Vector positionDiff = ray.pos - center;
  float b = 2 * (ray.dir).dot(positionDiff);
  float c = positionDiff.dot(positionDiff) - radius * radius;
  float discriminant = b * b - 4 * a * c;

  // Failed to intersect. sqrt(discriminant) is imaginary.
  if (discriminant < 0) {
    return false;
  }
  float t0 = (-b + sqrt(discriminant)) / (2 * a);
  float t1 = (-b - sqrt(discriminant)) / (2 * a);
  float hit = -std::numeric_limits<float>::infinity();
  if (t0 > 0 && t1 > 0) {
    // Pick the closer hit
    hit = std::min(t0, t1);
  } else if ((t0 > 0 && t1 < 0) || (t0 < 0 && t1 > 0)) {
    // Hit a point in front of the eye and another point behind the eye,
    // so pick the one in front of they eye
    hit = std::max(t0, t1);
  }
  return hit >= ray.t_min && hit <= ray.t_max;
}
