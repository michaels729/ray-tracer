/*
 * loadscene.h
 *
 *  Created on: Sep 29, 2016
 *      Author: mbs729
 */

#ifndef LOADSCENE_H_
#define LOADSCENE_H_

#include <stack>
#include <string>

#include "geo/Matrix.h"

void rightMultiply(const Matrix & M, std::stack<Matrix> &transfstack);
void loadScene(std::string file);

#endif /* LOADSCENE_H_ */
