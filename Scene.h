/*
 * Scene.h
 *
 *  Created on: Sep 22, 2016
 *      Author: mbs729
 */

#ifndef SCENE_H_
#define SCENE_H_

class Sample;

class Scene {
public:
  Point eye;
  Sample cornerUpLeft, cornerUpRight, cornerBottomLeft, cornerBottomRight;
  int width, height;
  Scene(Point &eye, Sample &cornerUpLeft, Sample &cornerUpRight,
      Sample &cornerBottomLeft, Sample &cornerBottomRight, int width, int height);
  void render();
};

#endif /* SCENE_H_ */
