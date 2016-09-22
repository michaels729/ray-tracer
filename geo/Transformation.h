/*
 * Transformation.h
 *
 *  Created on: Sep 21, 2016
 *      Author: mbs729
 */

#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

class Transformation {
public:
  Matrix m, minvt;
  Transformation(Matrix m, Matrix minvt);
};

#endif /* TRANSFORMATION_H_ */
