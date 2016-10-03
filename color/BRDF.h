/*
 * BRDF.h
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#ifndef BRDF_H_
#define BRDF_H_

#include "Color.h"

struct BRDF {
  Color ka, ke, kd, ks;
  float shininess;
};

#endif /* BRDF_H_ */
