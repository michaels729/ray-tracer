/*
 * Normal.h
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#ifndef NORMAL_H_
#define NORMAL_H_
#include "Vector.h"

class Normal: public Vector {
public:
  Normal(float x, float y, float z);

  Normal operator+(Vector v) override;
  Normal operator-(Vector v) override;
};

#endif /* NORMAL_H_ */
