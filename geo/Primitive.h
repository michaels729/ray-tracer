/*
 * Primitive.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

class Primitive {
public:
  Primitive();
  virtual ~Primitive();

  virtual bool intersect(Ray &ray, float *thit, Intersection *in) = 0;
  virtual bool intersectP(Ray &ray) = 0;
  virtual bool getBRDF(LocalGeo &local, BRDF *brdf) = 0;
};

#endif /* PRIMITIVE_H_ */
