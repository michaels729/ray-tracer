/*
 * Camera.h
 *
 *  Created on: Oct 1, 2016
 *      Author: mbs729
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "geo/Point.h"
#include "geo/Ray.h"
#include "geo/Vector.h"
#include "Sample.h"

class Camera {
private:
  Point eye, center;
  Vector upinit;
  const float fovy;
  Vector w, u, v;

public:
  Camera(float lookfromx, float lookfromy, float lookfromz, float lookatx,
      float lookaty, float lookatz, float upx, float upy, float upz,
      float fovy);
  virtual ~Camera();
  void generateRay(const Sample &sample, Ray *ray, int width, int height) const;
};

#endif /* CAMERA_H_ */
