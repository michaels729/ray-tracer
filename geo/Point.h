/*
 * Point.h
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#ifndef GEOM_POINT_H_
#define GEOM_POINT_H_

class Point {
public:
  float x, y, z;
  Point();
  Point(float x, float y, float z);

  Vector operator+(Vector v);
  Vector operator-(Vector v);
};

#endif /* GEOM_POINT_H_ */
