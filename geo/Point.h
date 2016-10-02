/*
 * Point.h
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#ifndef GEOM_POINT_H_
#define GEOM_POINT_H_

class Vector;

class Point {
public:
  float x, y, z;
  Point();
  Point(float x, float y, float z);

  Point operator+(const Vector &v) const;
  Point operator-(const Vector &v) const;
  Vector operator-(const Point &p) const;
  Point operator-() const;
  const float operator[](int i) const;
};

#endif /* GEOM_POINT_H_ */
