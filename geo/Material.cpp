/*
 * Material.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Material.h"
#include "../color/Color.h"

Material::Material(Color &kd, Color &ks, Color &ka, Color &kr) {
  constantBRDF = BRDF(kd, ks, ka, kr);
}

Material::~Material() {
}

BRDF Material::getBRDF(LocalGeo &local, BRDF *brdf) {
  return constantBRDF;
}
