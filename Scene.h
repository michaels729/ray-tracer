/*
 * Scene.h
 *
 *  Created on: Sep 22, 2016
 *      Author: mbs729
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <string>

#include "Sampler.h"

class Camera;
class Film;
class RayTracer;

class Scene {
public:
  const Camera &camera;
  RayTracer &rayTracer;
  Film &film;
  int height, width;
  Sampler sampler;

  Scene(const Camera &camera, RayTracer &rayTracer, Film &film, int height,
      int width);
  virtual ~Scene();
  void render(std::string fname);
};

#endif /* SCENE_H_ */
