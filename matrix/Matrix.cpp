/*
 * Matrix.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: mbs729
 */

#include <iostream>
#include "Matrix.h"
#include "../geo/Vector.h"
using std::cout;

Matrix::Matrix(): Matrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 ,0, 0, 1) {}

Matrix::Matrix(float a, float b, float c,
       float d, float e, float f,
       float g, float h, float i): Matrix(a, b, c, 0, d, e, f, 0, g, h, i, 0, 0, 0, 0, 1) {}

Matrix::Matrix(float a, float b, float c, float d,
    float e, float f, float g, float h,
    float i, float j, float k, float l,
    float m, float n, float o, float p): mat{{a, b, c, d}, {e, f, g, h}, {i, j, k, l}, {m, n, o, p}} {}

Matrix Matrix::transpose() {
  return Matrix(mat[0][0], mat[1][0], mat[2][0], mat[3][0],
                mat[0][1], mat[1][1], mat[2][1], mat[3][1],
                mat[0][2], mat[1][2], mat[2][2], mat[3][2],
                mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
}

Matrix Matrix::operator*(float n) {
  return Matrix(mat[0][0] * n, mat[0][1] * n, mat[0][2] * n, mat[0][3] * n,
                mat[1][0] * n, mat[1][1] * n, mat[1][2] * n, mat[1][3] * n,
                mat[2][0] * n, mat[2][1] * n, mat[2][2] * n, mat[2][3] * n,
                mat[3][0] * n, mat[3][1] * n, mat[3][2] * n, mat[3][3] * n);
}

Matrix Matrix::rotate(const float degrees, const Vector &axis) {
  const float radians = degrees * pi / 180;
  const float cosRadians = cos(radians);
  const float sinRadians = sin(radians);
  Matrix aaT = Matrix(axis.x * axis.x, axis.x * axis.y, axis.x * axis.z,
                axis.x * axis.y, axis.y * axis.y, axis.y * axis.z,
                axis.x * axis.z, axis.y * axis.z, axis.z * axis.z);
  Matrix aStar = Matrix(0, -axis.z, axis.y,
                        axis.z, 0, -axis.x,
                        -axis.y, axis.x, 0);

  return cosRadians * Matrix(1) + (1 - cosRadians) * aaT + sinRadians * aStar;
}

Matrix Matrix::translate(const float& tx, const float& ty, const float& tz) {
  return Matrix(1, 0, 0, tx,
                0, 1, 0, ty,
                0, 0, 1, tz,
                0, 0, 0, 1);
}

Matrix Matrix::scale(const float& sx, const float& sy, const float& sz) {
  return Matrix(sx, 0, 0, 0,
              0, sy, 0, 0,
              0, 0, sz, 0,
              0, 0, 0, 1);
}

int main() {
  Matrix matrix = Matrix(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
  for (int i=0; i < 4; ++i) {
    for (int j=0; j < 4; ++j) {
      cout << matrix.mat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
  Matrix trans = matrix.transpose();
  for (int i=0; i < 4; ++i) {
    for (int j=0; j < 4; ++j) {
      cout << trans.mat[i][j] << ' ';
    }
    cout << '\n';
  }
}
