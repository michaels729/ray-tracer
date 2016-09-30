/*
 * PointLight.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "Light.h"

struct LocalGeo;
struct Ray;
class Color;

class PointLight: public Light {
public:
  PointLight();
  virtual ~PointLight();
  void generateLightRay(const LocalGeo &local, Ray *lray, Color *lcolor) override;
};

#endif /* POINTLIGHT_H_ */
