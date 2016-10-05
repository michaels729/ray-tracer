/*
 * Attenuation.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: mbs729
 */

#include "Attenuation.h"

Attenuation::Attenuation() :
    Attenuation(1, 0, 0) {
}

Attenuation::Attenuation(float constant, float linear, float quadratic) :
    constant(constant), linear(linear), quadratic(quadratic) {
}

Attenuation::~Attenuation() {
}

float Attenuation::calc(float dist) const {
  return 1 / (constant + linear * dist + quadratic * dist * dist);
}
