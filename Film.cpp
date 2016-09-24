/*
 * Film.cpp
 *
 *  Created on: Sep 23, 2016
 *      Author: mbs729
 */

#include <malloc.h>
#include "Film.h"
#include "Sample.h"
#include "Sampler.h"
#include "color/Color.h"

Film::Film(int height, int width): height(height), width(width) {
  image = (Color**) malloc(height * sizeof(Color*));
  for (int i = 0; i < height; ++i) {
    image[i] = (Color*) malloc(width * sizeof(Color));
    for (int j = 0; j < width; ++j) {
      image[i][j] = Color(0, 0, 0);
    }
  }
}

Film::~Film() {
  for (int i = 0; i < height; ++i) {
    free(image[i]);
  }
  free(image);
}

void Film::commit(Sample &sample, Color &color) {
  image[sample.y][sample.x] = color;
}

void Film::writeImage() {
}
