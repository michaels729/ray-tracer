/*
 * Scene_test.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: mbs729
 */

#include <string>
#include <FreeImage.h>
#include "Film.h"
#include "Scene.h"

int main() {
  int height = 100, width = 100;
  Film film = Film(height, width);
  Scene scene = Scene(film, height, width);
  scene.render("grey.png");
}
