/*
 * Scene.h
 *
 *  Created on: Sep 22, 2016
 *      Author: mbs729
 */

#include "Sampler.h"

#ifndef SCENE_H_
#define SCENE_H_

class Film;
class Sample;
class Point;

class Scene {
private:
  Film &film;
  //  Point &eye;
  //  Sample &cornerUpLeft, &cornerUpRight, &cornerBottomLeft, &cornerBottomRight;
  int height, width;
  Sampler sampler;

public:
  Scene(Film &film, int height, int width);
  virtual ~Scene();
//  Scene(Sampler &sampler, Film &film, Point &eye, Sample &cornerUpLeft,
//      Sample &cornerUpRight, Sample &cornerBottomLeft, Sample &cornerBottomRight,
//      int height, int width);
  void render(std::string fname);
};

#endif /* SCENE_H_ */
