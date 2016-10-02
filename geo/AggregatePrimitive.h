/*
 * AggregatePrimitive.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include <vector>

#include "Primitive.h"

struct BRDF;
struct Intersection;
struct LocalGeo;
struct Ray;

#ifndef AGGREGATEPRIMITIVE_H_
#define AGGREGATEPRIMITIVE_H_

class AggregatePrimitive: public Primitive {
private:
  std::vector<Primitive*> &list;

public:
  AggregatePrimitive(std::vector<Primitive*> &list);
  virtual ~AggregatePrimitive();
  bool intersect(const Ray &ray, float *thit, Intersection *in) override;
  bool intersectP(const Ray &ray) const override;
  void getBRDF(LocalGeo &local, BRDF *brdf) override;
};

#endif /* AGGREGATEPRIMITIVE_H_ */
