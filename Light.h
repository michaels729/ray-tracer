/*
 * Light.h
 *
 *  Created on: Sep 26, 2016
 *      Author: mbs729
 */

#ifndef LIGHT_H_
#define LIGHT_H_

class Light {
public:
  Light();
  virtual ~Light();
  virtual void generateLightRay(const LocalGeo &local, Ray *lray, Color *lcolor) = 0;
};

#endif /* LIGHT_H_ */
