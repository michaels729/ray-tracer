/*
 * Camera.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: mbs729
 */

#include "Camera.h"
#include "Sample.h"
#include "geo/Vector.h"
#include "geo/Ray.h"

Camera::Camera(float lookfromx, float lookfromy, float lookfromz, float lookatx,
    float lookaty, float lookatz, float upx, float upy, float upz, float fovy) :
    Camera(Vector(lookfromx, lookfromy, lookfromz),
        Vector(lookatx, lookaty, lookatz), Vector(upx, upy, upz), fovy) {
}

Camera::Camera(Vector eye, Vector center, Vector upinit, float fovy) :
    eye(eye), center(center), upinit(upinit), fovy(fovy) {
}

Camera::~Camera() {
}

void Camera::generateRay(const Sample &sample, Ray *ray) {

}
