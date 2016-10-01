/*
 * Material.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "../color/BRDF.h"

class Color;
struct LocalGeo;

#ifndef MATERIAL_H_
#define MATERIAL_H_

class Material {
private:
  BRDF constantBRDF;

public:
  Material(Color &kd, Color &ks, Color &ka, Color &kr);
  virtual ~Material();
  void getBRDF(LocalGeo &local, BRDF *brdf);
};

#endif /* MATERIAL_H_ */
