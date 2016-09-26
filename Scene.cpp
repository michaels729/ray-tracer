/*
 * Scene.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: mbs729
 */

#include <string>
#include <FreeImage.h>
#include "Film.h"
#include "Scene.h"
#include "Sample.h"
#include "geo/Point.h"
#include "color/Color.h"

//Scene::Scene(Sampler &sampler, Film &film, Point &eye, Sample &cornerUpLeft,
//    Sample &cornerUpRight, Sample &cornerBottomLeft, Sample &cornerBottomRight,
//    int height, int width) :
//    sampler(sampler), film(film), eye(eye), cornerUpLeft(cornerUpLeft), cornerUpRight(
//        cornerUpRight), cornerBottomLeft(cornerBottomLeft), cornerBottomRight(
//        cornerBottomRight), height(height), width(width) {
//}

Scene::Scene(Film &film, int height, int width):
    film(film), height(height), width(width), sampler(Sampler(height, width)) {
}

Scene::~Scene() {
}

void Scene::render(std::string fname) {
  Sample sample;
  Color mockColor = Color(.5, .5, .5);
  while (sampler.getSample(&sample)) {
    film.commit(sample, mockColor);
  }
  film.writeImage(fname);
}

int main() {
  int height = 100, width = 100;
  Film film = Film(height, width);
  Scene scene = Scene(film, height, width);
  //film.printImageBuffer();
  scene.render("white.png");
}
