/*
 * Scene.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: mbs729
 */

#include "Scene.h"
#include "Sample.h"
#include "geo/Point.h"

Scene::Scene(Point &eye, Sample &cornerUpLeft, Sample &cornerUpRight,
    Sample &cornerBottomLeft, Sample &cornerBottomRight, int width, int height) :
    eye(eye), cornerUpLeft(cornerUpLeft), cornerUpRight(cornerUpRight), cornerBottomLeft(
        cornerBottomLeft), cornerBottomRight(cornerBottomRight), width(width), height(
        height) {
}

void Scene::render() {
}
