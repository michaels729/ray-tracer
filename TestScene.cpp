/*
 * TestScene.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: mbs729
 */

#include "color/Color.h"
#include "color/Material.h"
#include "Camera.h"
#include "Film.h"
#include "geo/GeometricPrimitive.h"
#include "geo/Matrix.h"
#include "geo/Sphere.h"
#include "geo/Transformation.h"
#include "RayTracer.h"
#include "Scene.h"

int main() {
  int height = 100, width = 100, maxDepth = 5;
  Camera camera = Camera(0, -4, 4, 0, -1, 0, 0, 1, 1, 45);

  Sphere sphere = Sphere(0, 0, -1, 1);
  Transformation objToWorld = Transformation(Matrix(1.0));
  Transformation worldToObj = Transformation(Matrix(1.0));
  Color kd, ks, ka, kr;
  Material material = Material(kd, ks, ka, kr);
  GeometricPrimitive geoPrim = GeometricPrimitive(objToWorld, worldToObj,
      &sphere, &material);
  RayTracer raytracer = RayTracer(maxDepth, geoPrim);

  Film film = Film(height, width);

  Scene scene = Scene(camera, raytracer, film, height, width);
  scene.render("result1.png");
}
