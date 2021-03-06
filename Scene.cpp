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
#include <omp.h>

Scene::Scene(const Camera &camera, RayTracer &rayTracer, Film &film, int width,
    int height) :
    camera(camera), rayTracer(rayTracer), film(film), width(width), height(
        height) {
}

Scene::~Scene() {
}

void Scene::render(std::string fname) {
  int size = width * height;
  # pragma omp parallel for schedule(dynamic)
  for (int i = 0; i < size; ++i) {
    int y = i % width;
    int x = i / width;
    Sample sample(x, y);
    //std::cout << '(' << y << ", " << x << ")\n";
    Ray ray = { Point(0, 0, 0), Vector(0, 0, 0), 0, 0 };
    camera.generateRay(sample, &ray, width, height);

    Color color;
    rayTracer.trace(ray, &color);
    film.commit(sample, color);
  }
  film.writeImage(fname);
}
