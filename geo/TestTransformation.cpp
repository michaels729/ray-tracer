/*
 * TestTransformation.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: mbs729
 */

#include <iostream>

#include "LocalGeo.h"
#include "Matrix.h"
#include "Point.h"
#include "Transformation.h"

int main() {
  Point pos;
  pos << 6, 3, 8;
  Vector v;
  v << 3, 4, 5;
  v.normalize();
  LocalGeo lg = { pos, v };

  Matrix transMat;
  transMat << 2, 0, 0, 0,
              0, 3, 0, 0,
              0, 0, 5, 0,
              0, 0, 0, 1;
  Transformation trans = Transformation(transMat);
  Transformation transInv = Transformation(transMat.inverse());

  LocalGeo transGeo = trans * lg;
  Point transPos = transGeo.pos;
  Vector transVec = trans * v;

  LocalGeo revertedGeo = transInv * transGeo;
  Point revertedPos = revertedGeo.pos;
  Vector revertedVec = transInv * transVec;

  std::cout << "Original Position: (" << pos[0] << ", " << pos[1] << ", " << pos[2] << ")\n";
  std::cout << "Transformed Position: (" << transPos[0] << ", " << transPos[1] << ", " << transPos[2] << ")\n";
  std::cout << "Reverted Position: (" << revertedPos[0] << ", " << revertedPos[1] << ", " << revertedPos[2] << ")\n\n";

  std::cout << "Original Vector: (" << v[0] << ", " << v[1] << ", " << v[2] << ")\n";
  std::cout << "Transformed Vector: (" << transVec[0] << ", " << transVec[1] << ", " << transVec[2] << ")\n";
  std::cout << "Reverted Vector: (" << revertedVec[0] << ", " << revertedVec[1] << ", " << revertedVec[2] << ")\n\n";

  return 0;
}
