/*
 * Material.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "BRDF.h"

struct LocalGeo;

class Material {
private:
  BRDF constantBRDF;

public:
  Material(Color ka, Color ke, Color kd, Color ks, float shininess,
      Attenuation atten);
  virtual ~Material();
  void getBRDF(LocalGeo &local, BRDF *brdf);
};

#endif /* MATERIAL_H_ */
