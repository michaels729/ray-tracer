/*
 * Attenuation.h
 *
 *  Created on: Oct 4, 2016
 *      Author: mbs729
 */

#ifndef LIGHT_ATTENUATION_H_
#define LIGHT_ATTENUATION_H_

class Attenuation {
private:
  float constant, linear, quadratic;
public:
  Attenuation();
  Attenuation(float constant, float linear, float quadratic);
  virtual ~Attenuation();
  float calc(float dist) const;
};

#endif /* LIGHT_ATTENUATION_H_ */
