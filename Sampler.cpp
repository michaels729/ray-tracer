/*
 * Sampler.cpp
 *
 *  Created on: Sep 23, 2016
 *      Author: mbs729
 */

#include "Sampler.h"

#include "Sample.h"

Sampler::Sampler(int width, int height): x(0), y(0), width(width), height(height) {}

bool Sampler::getSample(Sample *sample) {
  if (height == 0 || width == 0 || x == height) {
    return false;
  }

  sample->x = x;
  sample->y = y;

  y = (y + 1) % width;
  if (y == 0) {
    ++x;
  }
  return true;
}
