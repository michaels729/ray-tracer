/*
 * Film.cpp
 *
 *  Created on: Sep 23, 2016
 *      Author: mbs729
 */

#include "Film.h"

#include <math.h>
#include <iostream>

#include "color/Color.h"
#include "Sample.h"

using std::cout;

Film::Film(int height, int width) :
    height(height), width(width) {
  image = new BYTE[height * width * 3];
  for (int i = 0; i < height * width * 3; ++i) {
    image[i] = 0;
  }
}

Film::~Film() {
  delete[] image;
}

void Film::commit(const Sample &sample, const Color &color) {
  int offset = (sample.y * width + sample.x) * 3;
  image[offset + 0] = floatToHex(color.r);
  image[offset + 1] = floatToHex(color.g);
  image[offset + 2] = floatToHex(color.b);
}

BYTE Film::floatToHex(float f) {
  if (f < 0.0 || f > 1.0) {
    cout << f << " is not a valid rgb float value\n";
  }
  return (BYTE) floor(f == 1.0 ? 255 : f * 256.0);
}

void Film::writeImage(std::string fname) {
  FreeImage_Initialise();
  FIBITMAP* convertedImage = FreeImage_ConvertFromRawBits(image, width, height,
      width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);
  FreeImage_Save(FIF_PNG, convertedImage, fname.c_str(), 0);
  FreeImage_DeInitialise();
}

void Film::printImageBuffer() {
  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      int offset = (j * width + i) * 3;
      cout << std::to_string(image[offset]) << ' ';
    }
    cout << '\n';
  }
}
