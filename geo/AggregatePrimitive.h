/*
 * AggregatePrimitive.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include <vector>
#include "Primitive.h"

#ifndef AGGREGATEPRIMITIVE_H_
#define AGGREGATEPRIMITIVE_H_

class AggregatePrimitive: public Primitive {
private:
  std::vector<Primitive*> list;

public:
  AggregatePrimitive(std::vector<Primitive*> list);
  virtual ~AggregatePrimitive();
  bool intersect(Ray &ray, float *thit, Intersection *in) override;
  bool intersectP(Ray &ray) override;
  bool getBRDF(LocalGeo &local, BRDF *brdf) override;
};

#endif /* AGGREGATEPRIMITIVE_H_ */
