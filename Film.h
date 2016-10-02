/*
 * Film.h
 *
 *  Created on: Sep 23, 2016
 *      Author: mbs729
 */

#ifndef FILM_H_
#define FILM_H_

#include <FreeImage.h>
#include <string>

class Color;
class Sample;

class Film {
private:
  BYTE* image;
  int height, width;
  BYTE floatToHex(float f);

public:
  Film(int width, int height);
  virtual ~Film();
  void commit(const Sample &sample, const Color &color);
  void writeImage(std::string fname);
  void printImageBuffer();
};

#endif /* FILM_H_ */
