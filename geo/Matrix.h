/*
 * Matrix.h
 *
 *  Created on: Sep 20, 2016
 *      Author: mbs729
 */

#ifndef MATRIX_MATRIX_H_
#define MATRIX_MATRIX_H_

const float pi = 3.14159265;

class Vector;

class Matrix {
private:
  float mat[4][4];

public:
  Matrix();

  Matrix(float a);

  Matrix(float a, float b, float c,
         float d, float e, float f,
         float g, float h, float i);

  Matrix(float a, float b, float c, float d,
         float e, float f, float g, float h,
         float i, float j, float k, float l,
         float m, float n, float o, float p);

  Matrix(float arr[][4]);

  Matrix operator+(const Matrix &m);
  Matrix operator-(const Matrix &m);
  Matrix operator*(const float n);
  Matrix operator*(const Matrix &m);
  const float* operator[](int i) const;
  Matrix transpose();
  Matrix inverse();

  static Matrix rotate(const float degrees, const Vector &axis);
  static Matrix translate(const float &tx, const float &ty, const float &tz);
  static Matrix scale(const float &sx, const float &sy, const float &sz);
};

#endif /* MATRIX_MATRIX_H_ */
