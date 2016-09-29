/*
 * Matrix_test.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: mbs729
 */

#include <iostream>
#include "Matrix.h"
using std::cout;

int main() {
  cout << "Original Matrix:\n";
  Matrix matrix = Matrix(1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 0, 1, 4, 2, 3);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  cout << "Testing Matrix Multiply via squaring:\n";
  Matrix product = matrix * matrix;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << product[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  cout << "Testing Transpose:\n";
  Matrix trans = matrix.transpose();
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << trans[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  cout << "Testing inverse:\n";
  Matrix inv = matrix.inverse();
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << inv[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}
