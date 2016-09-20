/*
 * Matrix.h
 *
 *  Created on: Sep 20, 2016
 *      Author: mbs729
 */

#ifndef MATRIX_MATRIX_H_
#define MATRIX_MATRIX_H_

const float pi = 3.14159265;

class Matrix {
public:
  float mat[4][4];
  Matrix();

  Matrix(float a, float b, float c,
         float d, float e, float f,
         float g, float h, float i);

  Matrix(float a, float b, float c, float d,
         float e, float f, float g, float h,
         float i, float j, float k, float l,
         float m, float n, float o, float p);

  Matrix operator*(float n);
  Matrix operator*(Matrix mat);
  Matrix transpose();
  Matrix inverse();
  float determinant();
  Matrix adjunct();

  static Matrix rotate(const float degrees, const Vector &axis);
  static Matrix translate(const float &tx, const float &ty, const float &tz);
  static Matrix scale(const float &sx, const float &sy, const float &sz);
};

#endif /* MATRIX_MATRIX_H_ */
