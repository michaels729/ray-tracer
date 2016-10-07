/*
 * PointLight.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "../color/Color.h"
#include "../geo/Point.h"
#include "Light.h"

class PointLight: public Light {
private:
  Point pos;
  Color color;

public:
  PointLight(float x, float y, float z, float r, float g, float b);
  virtual ~PointLight();
  void generateLightRay(const LocalGeo &local, Ray *lray, Color *lcolor)
      override;
  Point getPos() override;
};

#endif /* POINTLIGHT_H_ */
