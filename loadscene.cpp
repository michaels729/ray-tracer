#include "loadscene.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

#include "color/Color.h"
#include "color/Material.h"
#include "Camera.h"
#include "Film.h"
#include "geo/AggregatePrimitive.h"
#include "geo/GeometricPrimitive.h"
#include "geo/Matrix.h"
#include "geo/Point.h"
#include "geo/Sphere.h"
#include "geo/Transformation.h"
#include "geo/Triangle.h"
#include "geo/Vector.h"
#include "RayTracer.h"
#include "Scene.h"

void rightMultiply(const Matrix & M, std::stack<Matrix> &transfstack) {
  Matrix &T = transfstack.top();
  T = T * M;
}

void loadScene(std::string file) {

  // Dimensions for the output image file
  int width, height;
  // Number of bounces for a ray; Default: 5
  int maxDepth = 5;
  // Set a default filename
  std::string filename = "image.png";
  // Initialize Camera;
  Camera *camera;
  // Initialize Film;
  Film *film;
  // Initialize list of vertices
  std::vector<Point*> vertices;
  // Initialize list of shapes
  std::vector<Shape*> shapeList;
  // Initialize list of materials
  std::vector<Material*> materialList;
  // Initialize list to hold primitives
  std::vector<Primitive*> primList;
  // Initialize global ambient; Default: (r, g, b) = (.2, .2, .2)
  Color ka = Color(.2, .2, .2);
  // Initialize emissive (ke), diffuse (kd), specular (ks)
  Color ke, kd, ks;
  // Initialize shininess
  float shininess;

  std::ifstream inpfile(file.c_str());
  if (!inpfile.is_open()) {
    std::cout << "Unable to open file" << std::endl;
  } else {
    std::string line;
    std::stack<Matrix> transfstack;
    transfstack.push(Matrix(1.0));

    while (inpfile.good()) {
      std::vector<std::string> splitline;
      std::string buf;

      std::getline(inpfile, line);
      std::stringstream ss(line);

      while (ss >> buf) {
        splitline.push_back(buf);
      }
      //Ignore blank lines
      if (splitline.size() == 0) {
        continue;
      }

      //Ignore comments
      if (splitline[0][0] == '#') {
        continue;
      }

      //Valid commands:
      //size width height
      //  must be first command of file, controls image size
      else if (!splitline[0].compare("size")) {
        width = atoi(splitline[1].c_str());
        height = atoi(splitline[2].c_str());
        film = new Film(height, width);
      }
      //maxdepth depth
      //  max # of bounces for ray (default 5)
      else if (!splitline[0].compare("maxdepth")) {
        maxDepth = atoi(splitline[1].c_str());
      }
      //output filename
      //  output file to write image to 
      else if (!splitline[0].compare("output")) {
        filename = splitline[1];
      }

      //camera lookfromx lookfromy lookfromz lookatx lookaty lookatz upx upy upz fov
      //  speciﬁes the camera in the standard way, as in homework 2.
      else if (!splitline[0].compare("camera")) {
        // lookfrom:
        float lookfromx = atof(splitline[1].c_str());
        float lookfromy = atof(splitline[2].c_str());
        float lookfromz = atof(splitline[3].c_str());
        // lookat:
        float lookatx = atof(splitline[4].c_str());
        float lookaty = atof(splitline[5].c_str());
        float lookatz = atof(splitline[6].c_str());
        // up:
        float upx = atof(splitline[7].c_str());
        float upy = atof(splitline[8].c_str());
        float upz = atof(splitline[9].c_str());
        // fovy:
        float fovy = atof(splitline[10].c_str());
        camera = new Camera(lookfromx, lookfromy, lookfromz,
                            lookatx, lookaty, lookatz,
                            upx, upy, upz,
                            fovy);
      }

      //sphere x y z radius
      //  Deﬁnes a sphere with a given position and radius.
      else if (!splitline[0].compare("sphere")) {
        // Create new sphere:
        //   Store 4 numbers
        float x = atof(splitline[1].c_str());
        float y = atof(splitline[2].c_str());
        float z = atof(splitline[3].c_str());
        float r = atof(splitline[4].c_str());
        //   Store current property values
        Sphere *sphere = new Sphere(x, y, z, r);
        Material *material = new Material(ka, ke, kd, ks, shininess);
        //   Store current top of matrix stack
        Matrix objToWorldMat = transfstack.top();
        Transformation objToWorld = Transformation(objToWorldMat);
        Transformation worldToObj = Transformation(objToWorldMat.inverse());
        GeometricPrimitive *prim = new GeometricPrimitive(
            objToWorld, worldToObj,
            sphere, material);
        shapeList.push_back(sphere);
        materialList.push_back(material);
        primList.push_back(prim);
      }
      //maxverts number
      //  Deﬁnes a maximum number of vertices for later triangle speciﬁcations. 
      //  It must be set before vertices are deﬁned.
      else if (!splitline[0].compare("maxverts")) {
        // Using an STL vector, so ignoring this
      }
      //maxvertnorms number
      //  Deﬁnes a maximum number of vertices with normals for later speciﬁcations.
      //  It must be set before vertices with normals are deﬁned.
      else if (!splitline[0].compare("maxvertnorms")) {
        // Care if you want
      }
      //vertex x y z
      //  Deﬁnes a vertex at the given location.
      //  The vertex is put into a pile, starting to be numbered at 0.
      else if (!splitline[0].compare("vertex")) {
        float x = atof(splitline[1].c_str());
        float y = atof(splitline[2].c_str());
        float z = atof(splitline[3].c_str());
        Point *vertex = new Point(x, y , z);
        vertices.push_back(vertex);
      }
      //vertexnormal x y z nx ny nz
      //  Similar to the above, but deﬁne a surface normal with each vertex.
      //  The vertex and vertexnormal set of vertices are completely independent
      //  (as are maxverts and maxvertnorms).
      else if (!splitline[0].compare("vertexnormal")) {
        // x: atof(splitline[1].c_str()),
        // y: atof(splitline[2].c_str()),
        // z: atof(splitline[3].c_str()));
        // nx: atof(splitline[4].c_str()),
        // ny: atof(splitline[5].c_str()),
        // nz: atof(splitline[6].c_str()));
        // Create a new vertex+normal with these 6 values, store in some array
      }
      //tri v1 v2 v3
      //  Create a triangle out of the vertices involved (which have previously been speciﬁed with
      //  the vertex command). The vertices are assumed to be speciﬁed in counter-clockwise order. Your code
      //  should internally compute a face normal for this triangle.
      else if (!splitline[0].compare("tri")) {
        // Create new triangle:
        //   Store pointer to array of vertices
        //   Store 3 integers to index into array
        int v1 = atoi(splitline[1].c_str());
        int v2 = atoi(splitline[2].c_str());
        int v3 = atoi(splitline[3].c_str());
        //   Store current property values
        Point *ver1 = vertices[v1];
        Point *ver2 = vertices[v2];
        Point *ver3 = vertices[v3];
        Triangle *tri = new Triangle(ver1, ver2, ver3);
        Material *material = new Material(ka, ke, kd, ks, shininess);
        //   Store current top of matrix stack
        Matrix objToWorldMat = transfstack.top();
        Transformation objToWorld = Transformation(objToWorldMat);
        Transformation worldToObj = Transformation(objToWorldMat.inverse());
        GeometricPrimitive *prim = new GeometricPrimitive(
            objToWorld, worldToObj,
            tri, material);
        shapeList.push_back(tri);
        materialList.push_back(material);
        primList.push_back(prim);
      }
      //trinormal v1 v2 v3
      //  Same as above but for vertices speciﬁed with normals.
      //  In this case, each vertex has an associated normal, 
      //  and when doing shading, you should interpolate the normals 
      //  for intermediate points on the triangle.
      else if (!splitline[0].compare("trinormal")) {
        // v1: atof(splitline[1].c_str())
        // v2: atof(splitline[2].c_str())
        // v3: atof(splitline[3].c_str())
        // Create new triangle:
        //   Store pointer to array of vertices (Different array than above)
        //   Store 3 integers to index into array
        //   Store current property values
        //   Store current top of matrix stack
      }

      //translate x y z
      //  A translation 3-vector
      else if (!splitline[0].compare("translate")) {
        float x = atof(splitline[1].c_str());
        float y = atof(splitline[2].c_str());
        float z = atof(splitline[3].c_str());
        // Update top of matrix stack
        rightMultiply(Matrix::translate(x, y, z), transfstack);
      }
      //rotate x y z angle
      //  Rotate by angle (in degrees) about the given axis as in OpenGL.
      else if (!splitline[0].compare("rotate")) {
        float x = atof(splitline[1].c_str());
        float y = atof(splitline[2].c_str());
        float z = atof(splitline[3].c_str());
        float angleDegrees = atof(splitline[4].c_str());
        Vector axis = Vector(x, y, z);
        // Update top of matrix stack
        rightMultiply(Matrix::rotate(angleDegrees, axis), transfstack);
      }
      //scale x y z
      //  Scale by the corresponding amount in each axis (a non-uniform scaling).
      else if (!splitline[0].compare("scale")) {
        float x = atof(splitline[1].c_str());
        float y = atof(splitline[2].c_str());
        float z = atof(splitline[3].c_str());
        // Update top of matrix stack
        rightMultiply(Matrix::scale(x, y, z), transfstack);
      }
      //pushTransform
      //  Push the current modeling transform on the stack as in OpenGL. 
      //  You might want to do pushTransform immediately after setting 
      //   the camera to preserve the “identity” transformation.
      else if (!splitline[0].compare("pushTransform")) {
        transfstack.push(transfstack.top());
      }
      //popTransform
      //  Pop the current transform from the stack as in OpenGL. 
      //  The sequence of popTransform and pushTransform can be used if 
      //  desired before every primitive to reset the transformation 
      //  (assuming the initial camera transformation is on the stack as 
      //  discussed above).
      else if (!splitline[0].compare("popTransform")) {
        if (transfstack.size() <= 1) {
          std::cerr << "Stack has no elements.  Cannot Pop\n";
        } else {
          transfstack.pop();
        }
      }

      //directional x y z r g b
      //  The direction to the light source, and the color, as in OpenGL.
      else if (!splitline[0].compare("directional")) {
        // x: atof(splitline[1].c_str()),
        // y: atof(splitline[2].c_str()),
        // z: atof(splitline[3].c_str()));
        // r: atof(splitline[4].c_str()),
        // g: atof(splitline[5].c_str()),
        // b: atof(splitline[6].c_str()));
        // add light to scene...
      }
      //point x y z r g b
      //  The location of a point source and the color, as in OpenGL.
      else if (!splitline[0].compare("point")) {
        // x: atof(splitline[1].c_str()),
        // y: atof(splitline[2].c_str()),
        // z: atof(splitline[3].c_str()));
        // r: atof(splitline[4].c_str()),
        // g: atof(splitline[5].c_str()),
        // b: atof(splitline[6].c_str()));
        // add light to scene...
      }
      //attenuation const linear quadratic
      //  Sets the constant, linear and quadratic attenuations 
      //  (default 1,0,0) as in OpenGL.
      else if (!splitline[0].compare("attenuation")) {
        // const: atof(splitline[1].c_str())
        // linear: atof(splitline[2].c_str())
        // quadratic: atof(splitline[3].c_str())
      }
      //ambient r g b
      //  The global ambient color to be added for each object 
      //  (default is .2,.2,.2)
      else if (!splitline[0].compare("ambient")) {
        float r = atof(splitline[1].c_str());
        float g = atof(splitline[2].c_str());
        float b = atof(splitline[3].c_str());
        ka = Color(r, g, b);
      }

      //diﬀuse r g b
      //  speciﬁes the diﬀuse color of the surface.
      else if (!splitline[0].compare("diffuse")) {
        float r = atof(splitline[1].c_str());
        float g = atof(splitline[2].c_str());
        float b = atof(splitline[3].c_str());
        kd = Color(r, g, b);
      }
      //specular r g b 
      //  speciﬁes the specular color of the surface.
      else if (!splitline[0].compare("specular")) {
        float r = atof(splitline[1].c_str());
        float g = atof(splitline[2].c_str());
        float b = atof(splitline[3].c_str());
        ks = Color(r, g, b);
      }
      //shininess s
      //  speciﬁes the shininess of the surface.
      else if (!splitline[0].compare("shininess")) {
        shininess = atof(splitline[1].c_str());
      }
      //emission r g b
      //  gives the emissive color of the surface.
      else if (!splitline[0].compare("emission")) {
        float r = atof(splitline[1].c_str());
        float g = atof(splitline[2].c_str());
        float b = atof(splitline[3].c_str());
        ke = Color(r, g, b);
      } else {
        std::cerr << "Unknown command: " << splitline[0] << std::endl;
      }
    }
    AggregatePrimitive *aggPrim = new AggregatePrimitive(primList);
    RayTracer *rayTracer = new RayTracer(maxDepth, *aggPrim);
    Scene *scene = new Scene(*camera, *rayTracer, *film, height, width);
    scene->render(filename);

    delete camera;
    delete film;
    delete aggPrim;
    for (Primitive *prim : primList) {
      delete prim;
    }
    for (Material *material : materialList) {
      delete material;
    }
    for (Shape *shape : shapeList) {
      delete shape;
    }
    for (Point *vertex : vertices) {
      delete vertex;
    }
    delete rayTracer;
    delete scene;
    inpfile.close();
  }
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    loadScene(std::string(argv[1]));
  }
  return 0;
}
