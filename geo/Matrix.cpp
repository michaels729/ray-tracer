/*
 * Matrix.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: mbs729
 */

#include "Matrix.h"

#include <cmath>

Matrix rotate(const float degrees, const Vector &axis) {
  const float radians = degrees * M_PI / 180;
  const float cosRadians = cos(radians);
  const float sinRadians = sin(radians);
  Eigen::Matrix3f aaT;
  aaT << axis[0] * axis[0], axis[0] * axis[1], axis[0] * axis[2],
         axis[1] * axis[0], axis[1] * axis[1], axis[1] * axis[2],
         axis[2] * axis[0], axis[2] * axis[1], axis[2] * axis[2];
  Eigen::Matrix3f aStar;
  aStar << 0, axis[2], -axis[1],
           -axis[2], 0, axis[0],
           axis[1], -axis[0], 0;

  Eigen::Matrix3f result = cosRadians * Eigen::Matrix3f::Identity()
      + (1 - cosRadians) * aaT
      + sinRadians * aStar;

  Matrix rotation;
  rotation << result(0, 0), result(1, 0), result(2, 0), 0,
              result(0, 1), result(1, 1), result(2, 1), 0,
              result(0, 2), result(1, 2), result(2, 2), 0,
              0           , 0           , 0           , 1;
  return rotation;
}

Matrix translate(const float& tx, const float& ty, const float& tz) {
  Matrix translation;
  translation << 1, 0, 0, tx,
                 0, 1, 0, ty,
                 0, 0, 1, tz,
                 0, 0, 0, 1;
  return translation;
}

Matrix scale(const float& sx, const float& sy, const float& sz) {
  Matrix sc;
  sc << sx, 0, 0, 0,
        0, sy, 0, 0,
        0, 0, sz, 0,
        0, 0, 0, 1;
  return sc;
}
