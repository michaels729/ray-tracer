/*
 * readfile.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: mbs729
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <deque>
#include <stack>
#include "readfile.h"
#include "geo/Vector.h"
#include "geo/Matrix.h"

using std::string;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::cerr;
using std::stack;

void rightmultiply(const Matrix& M, stack<Matrix>& transfstack) {
  Matrix &T = transfstack.top();
  T = T * M;
}

// Function to read the input data values
bool readvals(stringstream &s, const int numvals, float *values) {
  for (int i = 0; i < numvals; i++) {
    s >> values[i];
    if (s.fail()) {
      cout << "Failed reading value " << i << " will skip\n";
      return false;
    }
  }
  return true;
}

void readfile(const char* filename) {
  string str, cmd;
  ifstream in;
  in.open(filename);
  if (in.is_open()) {
    stack<Matrix> transfstack;
    transfstack.push(Matrix(1.0));

    getline(in, str);
    while (in) {
      // Ignore lines that contain only whitespace or are comments.
      if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
        stringstream s(str);
        s >> cmd;
        int i;
        bool validinput;

        if (cmd == "size") {
          validinput = readvals(s, 1, values);
          if (validinput) {

          }
        } else if (cmd == "maxdepth") {

        } else if (cmd == "output") {

        } else if (cmd == "camera") {
          validinput = readvals(s, 10, values); // 10 values eye cen up fov
          if (validinput) {
            // YOUR CODE FOR HW 2 HERE
            // Use all of values[0...9]
            // You may need to use the upvector fn in Transform.cpp
            // to set up correctly.
            // Set eyeinit upinit center fovy in variables.h
            Vector eyeinit = Vector((float) values[0], (float) values[1],
                (float) values[2]);
            Vector center = Vector((float) values[3], (float) values[4],
                (float) values[5]);
            Vector upinit = Vector((float) values[6], (float) values[7],
                (float) values[8]);
            float fovy = (float) values[9];
          }
        } else if (cmd == "sphere") {

        } else if (cmd == "maxverts") {

        } else if (cmd == "maxvertnorms") {

        } else if (cmd == "vertex") {

        } else if (cmd == "vertexnormal") {

        } else if (cmd == "tri") {

        } else if (cmd == "trinormal") {

        } else if (cmd == "translate") {

        } else if (cmd == "rotate") {

        } else if (cmd == "scale") {

        } else if (cmd == "pushTransform") {

        } else if (cmd == "popTransform") {

        } else if (cmd == "directional") {

        } else if (cmd == "point") {

        } else if (cmd == "attenuation") {

        } else if (cmd == "ambient") {

        } else if (cmd == "diffuse") {

        } else if (cmd == "specular") {

        } else if (cmd == "shininess") {

        } else if (cmd == "emission") {

        } else {
          cerr << "Unknown Command: " << cmd << " Skipping \n";
        }
      }
      getline(in, str);
    }

    // set eye
    // set up
    // set amount
  } else {
    cerr < "Unable to Open Input Data File " << filename << "\n";
    throw 2;
  }
}
