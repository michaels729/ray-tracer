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
  Normal();
  Normal(float x, float y, float z);
  Normal(const Vector &v);

  Normal operator+(const Vector &v) const;
  Normal operator-(const Vector &v) const;
};

#endif /* NORMAL_H_ */
