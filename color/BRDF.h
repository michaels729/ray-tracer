/*
 * BRDF.h
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#ifndef BRDF_H_
#define BRDF_H_

struct BRDF {
  Color kd, ks, ka, kr;
  float sp;
};

#endif /* BRDF_H_ */
