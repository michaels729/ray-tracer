/*
 * Material.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Material.h"

Material::Material(Color ka, Color ke, Color kd, Color ks, float shininess,
    Attenuation atten) :
    constantBRDF(BRDF { ka, ke, kd, ks, shininess, atten }) {
}

Material::~Material() {
}

void Material::getBRDF(LocalGeo &local, BRDF *brdf) {
  *brdf = constantBRDF;
}
