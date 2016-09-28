/*
 * Camera.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: mbs729
 */

#include "Camera.h"
#include "Sample.h"
#include "geo/Ray.h"

Camera::Camera(Vector eye, Vector center, Vector upinit, float fovy) :
    eye(eye), center(center), upinit(upinit), fovy(fovy) {
}

Camera::~Camera() {
}

void Camera::generateRay(const Sample &sample, Ray *ray) {

}
