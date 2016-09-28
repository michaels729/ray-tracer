/*
 * DirectionalLight.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef DIRECTIONALLIGHT_H_
#define DIRECTIONALLIGHT_H_

#include "Light.h"

class DirectionalLight: public Light {
public:
  DirectionalLight();
  virtual ~DirectionalLight();
  void generateLightRay(const LocalGeo &local, Ray *lray, Color *lcolor) override;
};

#endif /* DIRECTIONALLIGHT_H_ */
