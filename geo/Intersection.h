/*
 * Intersection.h
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "LocalGeo.h"

class Primitive;

struct Intersection {
  LocalGeo localGeo;
  Primitive *primitive;
};

#endif /* INTERSECTION_H_ */
