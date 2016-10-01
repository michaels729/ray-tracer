/*
 * GeometricPrimitive.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef GEOMETRICPRIMITIVE_H_
#define GEOMETRICPRIMITIVE_H_

#include "Primitive.h"
#include "Transformation.h"

struct BRDF;
struct Intersection;
class Material;
struct Ray;
class Shape;

struct LocalGeo;

class GeometricPrimitive: public Primitive {
private:
  Transformation objToWorld, worldToObj;
  Shape *shape;
  Material *material;

public:
  GeometricPrimitive(Transformation objToWorld, Transformation worldToObj,
      Shape *shape, Material *material);
  virtual ~GeometricPrimitive();
  bool intersect(const Ray &ray, float *thit, Intersection *in) override;
  bool intersectP(const Ray &ray) override;
  void getBRDF(LocalGeo &local, BRDF *brdf) override;
};

#endif /* GEOMETRICPRIMITIVE_H_ */
