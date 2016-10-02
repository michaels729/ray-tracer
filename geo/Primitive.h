/*
 * Primitive.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_
struct BRDF;
struct Intersection;
struct LocalGeo;
struct Ray;

class Primitive {
public:
  Primitive();
  virtual ~Primitive();

  virtual bool intersect(const Ray &ray, float *thit, Intersection *in) = 0;
  virtual bool intersectP(const Ray &ray) const = 0;
  virtual void getBRDF(LocalGeo &local, BRDF *brdf) = 0;
};

#endif /* PRIMITIVE_H_ */
