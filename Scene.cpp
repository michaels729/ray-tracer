/*
 * Scene.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: mbs729
 */

#include "Scene.h"

#include "color/Color.h"
#include "Camera.h"
#include "Film.h"
#include "geo/Point.h"
#include "geo/Ray.h"
#include "geo/Vector.h"
#include "RayTracer.h"
#include "Sample.h"

#include <iostream>

Scene::Scene(const Camera &camera, RayTracer &rayTracer, Film &film, int height,
    int width) :
    camera(camera), rayTracer(rayTracer), film(film), height(height), width(
        width), sampler(Sampler(height, width)) {
}

Scene::~Scene() {
}

void Scene::render(std::string fname) {
  Sample sample;
  int i = 0;
  while (sampler.getSample(&sample)) {
    std::cout << ++i << '\n';
    Ray ray = { Point(0, 0, 0), Vector(0, 0, 0), 0, 0 };
    camera.generateRay(sample, &ray, height, width);

    Color color;
    rayTracer.trace(ray, &color);
    film.commit(sample, color);
  }
  film.writeImage(fname);
}
