/*
 * Sampler.h
 *
 *  Created on: Sep 23, 2016
 *      Author: mbs729
 */

#ifndef SAMPLER_H_
#define SAMPLER_H_

class Sample;

class Sampler {
private:
  int x, y, width, height;
public:
  Sampler(int width, int height);
  bool getSample(Sample *sample);
};

#endif /* SAMPLER_H_ */
