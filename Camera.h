/*
 * Camera.h
 *
 *  Created on: Sep 26, 2016
 *      Author: mbs729
 */

#ifndef CAMERA_H_
#define CAMERA_H_

class Vector;

class Camera {
private:
  Vector eye, center, upinit;
  float fovy;
public:
  Camera(float lookfromx, float lookfromy, float lookfromz,
      float lookatx, float lookaty, float lookatz,
      float upx, float upy, float upz,
      float fovy);
  Camera(Vector eye, Vector center, Vector upinit, float fovy);
  virtual ~Camera();
  void generateRay(const Sample &sample, Ray *ray);
};

#endif /* CAMERA_H_ */
