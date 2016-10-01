/*
 * Material.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Material.h"

Material::Material(Color &kd, Color &ks, Color &ka, Color &kr) : constantBRDF(BRDF {kd, ks, ka, kr, 0}) {
}

Material::~Material() {
}

void Material::getBRDF(LocalGeo &local, BRDF *brdf) {
  *brdf = constantBRDF;
}
