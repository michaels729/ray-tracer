/*
 * Ray.h
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#ifndef RAY_H_
#define RAY_H_

// It represent the ray ray(t) = pos + t*dir, where t_min <= t <= t_max
struct Ray {
  Point pos;
  Vector dir;
  float t_min, t_max;
};

#endif /* RAY_H_ */
