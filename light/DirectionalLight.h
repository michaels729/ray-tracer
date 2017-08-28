/*
 * DirectionalLight.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef DIRECTIONALLIGHT_H_
#define DIRECTIONALLIGHT_H_

#include "../color/Color.h"
#include "../geo/LocalGeo.h"
#include "../geo/Ray.h"
#include "Light.h"
#include "../geo/Vector.h"

class DirectionalLight: public Light {
private:
  Vector dir;
  Color color;

public:
  DirectionalLight(float x, float y, float z, float r, float g, float b);
  virtual ~DirectionalLight();
  void generateLightRay(const LocalGeo &local, Ray *lray, Color *lcolor)
      override;
  Point getPos() override;
};

#endif /* DIRECTIONALLIGHT_H_ */
