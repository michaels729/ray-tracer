/*
 * GeometricPrimitive.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Transformation.h"

#ifndef GEOMETRICPRIMITIVE_H_
#define GEOMETRICPRIMITIVE_H_

struct LocalGeo;

class GeometricPrimitive : public Primitive {
private:
  Transformation objToWorld, worldToObj;
  Shape *shape;
  Material *material;

public:
  GeometricPrimitive(Transformation objToWorld, Transformation worldToObj, Shape *shape, Material *material);
  virtual ~GeometricPrimitive();
  bool intersect(Ray &ray, float *thit, Intersection *in) override;
  bool intersectP(Ray &ray) override;
  bool getBRDF(LocalGeo &local, BRDF *brdf) override;
};

#endif /* GEOMETRICPRIMITIVE_H_ */
