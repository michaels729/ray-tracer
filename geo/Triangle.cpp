/*
 * Triangle.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: mbs729
 */

#include "Triangle.h"

Triangle::Triangle(const Point &vertex1, const Point &vertex2, const Point &vertex3) :
    vertex1(vertex1), vertex2(vertex2), vertex3(vertex3) {
}

Triangle::~Triangle() {
}

bool Triangle::intersect(Ray &ray, float *thit, LocalGeo *local) {
}

bool Triangle::intersectP(Ray &ray) {
}
