/*
 * RayTracer.cpp
 *
 *  Created on: Sep 29, 2016
 *      Author: mbs729
 */

#include "RayTracer.h"

#include <algorithm>
#include <cmath>
#include <limits>

#include "color/BRDF.h"
#include "color/Color.h"
#include "geo/Intersection.h"
#include "geo/Point.h"
#include "geo/Primitive.h"
#include "geo/Ray.h"
#include "geo/Vector.h"

RayTracer::RayTracer(int maxDepth, Primitive &primitive,
    std::vector<Light*> lights) :
    maxDepth(maxDepth), primitive(primitive), lights(lights) {
}

RayTracer::~RayTracer() {
}

void RayTracer::trace(const Ray &ray, Color *color) {
  trace(ray, 0, color);
}

void RayTracer::trace(const Ray &ray, int depth, Color *color) {
  float thit;
  Intersection in;
  BRDF brdf = { Color(0, 0, 0), Color(0, 0, 0), Color(0, 0, 0), Color(0, 0, 0),
      0, Attenuation() };
  if (depth >= maxDepth || !primitive.intersect(ray, &thit, &in)) {
    color->setColor(0, 0, 0);
    return;
  }

  in.primitive->getBRDF(in.localGeo, &brdf);
  *color = brdf.ka + brdf.ke;

  for (Light *light : lights) {
    Ray lray = { Point(), Vector(), -std::numeric_limits<float>::infinity(),
        std::numeric_limits<float>::infinity() };
    Color lcolor;
    light->generateLightRay(in.localGeo, &lray, &lcolor);
    if (!primitive.intersectP(lray)) {
      Color tempColor = *color;
      Color shade = shading(ray, &in.localGeo, &brdf, lray, &lcolor);
      *color = tempColor + shade;
    }
  }
//  if (brdf.kr > 0) {
//    Color tempColor;
//    Ray reflectRay = createReflectRay(in.localGeo, ray);
//    trace(reflectRay, depth+1, &tempColor);
//    *color += brdf.kr * tempColor;
//  }
}

Color RayTracer::shading(const Ray &eyeRay, LocalGeo *lg, BRDF *brdf, Ray &lray,
    Color *lcolor) {
  Point objPos = lg->pos;
  Point lightPos = lray.pos;
  // Calculate the distance between the object and the light source,
  // then use the result to calculate the attenuation.
  float atten = brdf->atten.calc(
      sqrt(
          pow(lightPos.x - objPos.x, 2) + pow(lightPos.y - objPos.y, 2)
              + pow(lightPos.z - objPos.z, 2)));
  Color lightColor = *lcolor;

  // Need to calculate dot products with normalized direction.
  // Negate the direction so that we get the direction *toward* light.
  Vector lightDir = -lray.dir.normalize();
  Normal objNormal = lg->normal;

  // Lambert calculation for diffuse term
  Color kd = brdf->kd;
  float nDotL = objNormal.dot(lightDir);
  Color lambert = kd * lightColor * std::max(nDotL, 0.0f);

  // Phong calculation for specular term.
  Ray reflection = createReflectRay(*lg, lray);
  Vector halfVec = (-lightDir + reflection.dir).normalize();
  float nDotH = objNormal.dot(halfVec);
  Color ks = brdf->ks;
  float shininess = brdf->shininess;
  Color phong = ks * lightColor * std::pow(std::max(nDotH, 0.0f), shininess);

  return (lambert + phong) * atten;
}

Ray RayTracer::createReflectRay(LocalGeo &lg, Ray &ray) {
  float lDotN = ray.dir.dot(lg.normal);
  Ray reflect = { lg.pos, ray.dir + lg.normal * 2 * lDotN };
  return reflect;
}
