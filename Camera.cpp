/*
 * Camera.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: mbs729
 */

#include "Camera.h"

#include <cmath>

#include "geo/Ray.h"
#include "Sample.h"

Camera::Camera(float lookfromx, float lookfromy, float lookfromz, float lookatx,
    float lookaty, float lookatz, float upx, float upy, float upz, float fovy) :
    Camera(Point(lookfromx, lookfromy, lookfromz),
        Point(lookatx, lookaty, lookatz), Vector(upx, upy, upz), fovy) {
}

Camera::Camera(Point eye, Point center, Vector upinit, float fovy) :
    eye(eye), center(center), upinit(upinit), fovy(fovy), w(
        (eye - center).normalize()), u((upinit * w).normalize()), v(w * v) {
}

Camera::~Camera() {
}

void Camera::generateRay(const Sample &sample, Ray *ray, int height,
    int width) const {
  float fovyRad = fovy * 180 / PI;
  float fovxRad = (width / (float) height) * fovyRad;

  float alpha = float(fovxRad / 2) * (sample.x - ((float) width / 2)) / ((float) width / 2);
  float beta = tan(fovyRad / 2) * (((float) height / 2) - sample.y) / ((float) height / 2);

  ray->pos = eye;
  ray->dir = Vector(u * alpha + v * beta - w);
}