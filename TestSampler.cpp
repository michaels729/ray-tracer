/*
 * Scent_test.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: mbs729
 */

#include <iostream>
#include "Sampler.h"
#include "Sample.h"
using std::cout;

int main() {
  Sampler* sampler = new Sampler(6,3);
  Sample* s = new Sample();
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
