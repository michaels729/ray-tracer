/*
 * Matrix.h
 *
 *  Created on: Sep 20, 2016
 *      Author: mbs729
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <Eigen/Dense>

#include "Vector.h"

typedef Eigen::Matrix4f Matrix;

Matrix rotate(const float degrees, const Vector &axis);
Matrix translate(const float &tx, const float &ty, const float &tz);
Matrix scale(const float &sx, const float &sy, const float &sz);

#endif /* MATRIX_H_ */
