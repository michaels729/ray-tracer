/*
 * Film.h
 *
 *  Created on: Sep 23, 2016
 *      Author: mbs729
 */

#ifndef FILM_H_
#define FILM_H_

class Sample;
class Sampler;
class Color;

class Film {
private:
  int height, width;
  Color **image;

public:
  Film(int width, int height);
  virtual ~Film();
  void commit(Sample &sample, Color &color);
  void writeImage();
};

#endif /* FILM_H_ */
