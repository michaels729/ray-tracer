/*
 * TestTransformation.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: mbs729
 */

#include <iostream>

#include "LocalGeo.h"
#include "Matrix.h"
#include "Normal.h"
#include "Point.h"
#include "Transformation.h"

int main() {
  Point pos = Point(6, 3, 8);
  Vector v = Vector(3, 4, 5).normalize();
  Normal n = Normal(3, 4, 5);
  LocalGeo lg = { pos, n };

  Matrix transMat = Matrix(2, 0, 0, 0, 3, 0, 0, 0, 5);
  Transformation trans = Transformation(transMat);
  Transformation transInv = Transformation(transMat.inverse());

  LocalGeo transGeo = trans * lg;
  Point transPos = transGeo.pos;
  Normal transN = transGeo.normal;
  Vector transVec = trans * v;

  LocalGeo revertedGeo = transInv * transGeo;
  Point revertedPos = revertedGeo.pos;
  Normal revertedN = revertedGeo.normal;
  Vector revertedVec = transInv * transVec;

  std::cout << "Original Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")\n";
  std::cout << "Transformed Position: (" << transPos.x << ", " << transPos.y << ", " << transPos.z << ")\n";
  std::cout << "Reverted Position: (" << revertedPos.x << ", " << revertedPos.y << ", " << revertedPos.z << ")\n\n";

  std::cout << "Original Normal: (" << n.x << ", " << n.y << ", " << n.z << ")\n";
  std::cout << "Transformed Normal: (" << transN.x << ", " << transN.y << ", " << transN.z << ")\n";
  std::cout << "Reverted Normal: (" << revertedN.x << ", " << revertedN.y << ", " << revertedN.z << ")\n\n";

  std::cout << "Original Vector: (" << v.x << ", " << v.y << ", " << v.z << ")\n";
  std::cout << "Transformed Vector: (" << transVec.x << ", " << transVec.y << ", " << transVec.z << ")\n";
  std::cout << "Reverted Vector: (" << revertedVec.x << ", " << revertedVec.y << ", " << revertedVec.z << ")\n\n";

  return 0;
}
