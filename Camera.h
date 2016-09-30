/*
 * Camera.h
 *
 *  Created on: Sep 26, 2016
 *      Author: mbs729
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "geo/Point.h"
#include "geo/Vector.h"

struct Ray;
class Sample;

const float PI = 3.14159265;

class Camera {
private:
  const Point eye, center;
  const Vector upinit;
  const float fovy;
  const Vector w, u, v;
public:
  Camera(float lookfromx, float lookfromy, float lookfromz,
      float lookatx, float lookaty, float lookatz,
      float upx, float upy, float upz,
      float fovy);
  Camera(Point eye, Point center, Vector upinit, float fovy);
  virtual ~Camera();
  void generateRay(const Sample &sample, Ray *ray, int height, int width) const;
};

#endif /* CAMERA_H_ */
