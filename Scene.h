/*
 * Scene.h
 *
 *  Created on: Sep 22, 2016
 *      Author: mbs729
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <string>

class Camera;
class Film;
class RayTracer;

class Scene {
public:
  const Camera &camera;
  RayTracer &rayTracer;
  Film &film;
  int width, height;

  Scene(const Camera &camera, RayTracer &rayTracer, Film &film, int width,
      int height);
  virtual ~Scene();
  void render(std::string fname);
};

#endif /* SCENE_H_ */
