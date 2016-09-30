/*
 * Color.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: mbs729
 */

#include <iostream>
#include "Color.h"

Color::Color(float r, float g, float b): r(r), g(g), b(b) {}

Color Color::operator +(Color &c) {
  return Color(r + c.r, g + c.g, b + c.b);
}

Color Color::operator -(Color &c) {
  return Color(r - c.r, g - c.g, b - c.b);
}

Color Color::operator *(float n) {
  return Color(r * n, g * n, b * n);
}

Color Color::operator /(float n) {
  return Color(r / n, g / n, b / n);
}

void Color::setColor(float r, float g, float b) {
  this->r = r;
  this->g = g;
  this->b = b;
}
