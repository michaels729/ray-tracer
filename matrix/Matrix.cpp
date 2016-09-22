/*
 * Matrix.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: mbs729
 */

#include <iostream>
#include <math.h>
#include "Matrix.h"
#include "../geo/Vector.h"
using std::cout;

Matrix::Matrix(): Matrix(1) {
}

Matrix::Matrix(float a): Matrix(a, 0, 0, 0, 0, a, 0, 0, 0, 0, a, 0, 0, 0, 0, a) {
}

Matrix::Matrix(float a, float b, float c, float d, float e, float f, float g,
    float h, float i) :
    Matrix(a, b, c, 0, d, e, f, 0, g, h, i, 0, 0, 0, 0, 1) {
}

Matrix::Matrix(float a, float b, float c, float d, float e, float f, float g,
    float h, float i, float j, float k, float l, float m, float n, float o,
    float p) :
    mat { { a, b, c, d }, { e, f, g, h }, { i, j, k, l }, { m, n, o, p } } {
}

Matrix::Matrix(float arr[][4]) :
    Matrix(arr[0][0], arr[0][1], arr[0][2], arr[0][3], arr[1][0], arr[1][1],
        arr[1][2], arr[1][3], arr[2][0], arr[2][1], arr[2][2], arr[2][3],
        arr[3][0], arr[3][1], arr[3][2], arr[3][3]) {
}

Matrix Matrix::operator+(const Matrix &m) {
  float result[4][4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; i < 4; ++j) {
      result[i][j] = mat[i][j] + m.mat[i][j];
    }
  }
  return Matrix(result);
}

Matrix Matrix::operator-(const Matrix &m) {
  float result[4][4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; i < 4; ++j) {
      result[i][j] = mat[i][j] - m.mat[i][j];
    }
  }
  return Matrix(result);
}

Matrix Matrix::operator*(const float n) {
  float result[4][4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; i < 4; ++j) {
      result[i][j] = result[i][j] * n;
    }
  }
  return Matrix(result);
}

Matrix Matrix::operator*(const Matrix &m) {
  float result[4][4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      result[i][j] = 0;
      for (int k = 0; k < 4; ++k) {
        result[i][j] += mat[i][k] * m.mat[k][j];
      }
    }
  }
  return Matrix(result);
}

Matrix Matrix::transpose() {
  float transpose[4][4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      transpose[i][j] = mat[j][i];
    }
  }
  return Matrix(transpose);
}

Matrix Matrix::rotate(const float degrees, const Vector &axis) {
  const float radians = degrees * pi / 180;
  const float cosRadians = cos(radians);
  const float sinRadians = sin(radians);
  Matrix aaT = Matrix(axis.x * axis.x, axis.x * axis.y, axis.x * axis.z,
      axis.x * axis.y, axis.y * axis.y, axis.y * axis.z, axis.x * axis.z,
      axis.y * axis.z, axis.z * axis.z);
  Matrix aStar = Matrix(0, -axis.z, axis.y, axis.z, 0, -axis.x, -axis.y, axis.x,
      0);

  return Matrix(1) * cosRadians + aaT * (1 - cosRadians) + aStar * sinRadians;
}

Matrix Matrix::translate(const float& tx, const float& ty, const float& tz) {
  return Matrix(1, 0, 0, tx, 0, 1, 0, ty, 0, 0, 1, tz, 0, 0, 0, 1);
}

Matrix Matrix::scale(const float& sx, const float& sy, const float& sz) {
  return Matrix(sx, 0, 0, 0, 0, sy, 0, 0, 0, 0, sz, 0, 0, 0, 0, 1);
}

int main() {
  cout << "Original Matrix:\n";
  Matrix matrix = Matrix(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << matrix.mat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  cout << "Testing Matrix Multiply via squaring:\n";
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << matrix.mat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
  Matrix product = matrix * matrix;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << product.mat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  cout << "Testing Transpose:\n";
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << matrix.mat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
  Matrix trans = matrix.transpose();
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << trans.mat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}
