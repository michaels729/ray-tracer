/*
 * Material.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Material.h"

Material::Material(Color ka, Color ke, Color kd, Color ks, float shininess) :
    constantBRDF(BRDF { ka, ke, kd, ks, shininess }) {
}

Material::~Material() {
}

void Material::getBRDF(LocalGeo &local, BRDF *brdf) {
  *brdf = constantBRDF;
}
