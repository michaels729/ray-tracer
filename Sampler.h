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
  int x, y, height, width;
public:
  Sampler(int height, int width);
  bool getSample(Sample *sample);
};

#endif /* SAMPLER_H_ */
