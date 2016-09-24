/*
 * Sampler.cpp
 *
 *  Created on: Sep 23, 2016
 *      Author: mbs729
 */

#include <iostream>
#include "Sampler.h"
#include "Sample.h"
using std::cout;

Sampler::Sampler(int height, int width): x(0), y(0), height(height), width(width) {}

bool Sampler::getSample(Sample* sample) {
  if (height == 0 || width == 0 || y == height) {
    return false;
  }

  sample->x = x;
  sample->y = y;

  x = (x + 1) % width;
  if (x == 0) {
    ++y;
  }
  return true;
}

int main() {
  Sampler* sampler = new Sampler(6,3);
  Sample* s = (Sample*) malloc(sizeof(Sample));
  while(sampler->getSample(s)) {
    cout << '(' << s->x << ", " << s->y << ")\n";
  }
  delete sampler;
  cout << '\n';

  sampler = new Sampler(1, 3);
  while(sampler->getSample(s)) {
    cout << '(' << s->x << ", " << s->y << ")\n";
  }
  delete sampler;
  cout << '\n';

  sampler = new Sampler(3, 1);
  while(sampler->getSample(s)) {
    cout << '(' << s->x << ", " << s->y << ")\n";
  }
  delete sampler;
  cout << '\n';

  delete s;
}
