/*
 * Color.h
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:
  float r, g, b;
  Color();
  Color(float r, float g, float b);

  Color operator+(Color &c);
  Color operator-(Color &c);
  Color operator*(float n);
  Color operator*(Color &c);
  Color operator/(float n);
  void setColor(float r, float g, float b);
};

#endif /* COLOR_H_ */
