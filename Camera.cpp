/*
 * Camera.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: mbs729
 */

#include "Camera.h"

#include <cmath>
#include <limits>

Camera::Camera(float lookfromx, float lookfromy, float lookfromz, float lookatx,
    float lookaty, float lookatz, float upx, float upy, float upz, float fovy) :
    fovy(fovy) {
  eye << lookfromx, lookfromy, lookfromz;
  center << lookatx, lookaty, lookatz;
  upinit << upx, upy, upz;

  w = (eye - center).normalized();
  u = upinit.cross(w).normalized();
  v = w.cross(u).normalized();
}

Camera::~Camera() {
}

void Camera::generateRay(const Sample &sample, Ray *ray, int width,
    int height) const {
  float fovyRad = fovy * M_PI / 180;

  float tanFovyDiv2 = tan(fovyRad / 2);
  float tanFovxDiv2 = tanFovyDiv2 * (width / (float) height);

  float alpha = tanFovxDiv2 * ((sample.y + 0.5) - ((float) width / 2))
      / ((float) width / 2);
  float beta = tanFovyDiv2 * (((float) height / 2) - (sample.x + 0.5))
      / ((float) height / 2);

  ray->pos = eye;
  ray->dir = (u * alpha + v * beta - w).normalized();
  ray->t_min = 0.0f;
  ray->t_max = std::numeric_limits<float>::infinity();
}
