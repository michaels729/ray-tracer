/*
 * readfile.h
 *
 *  Created on: Sep 26, 2016
 *      Author: mbs729
 */

void rightmultiply(const Matrix &M, stack<Matrix> &transfstack);
bool readvals(stringstream &s, const int numvals, float *values);
void readfile(const char *filename);
