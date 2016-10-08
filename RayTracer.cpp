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
    Ray lray = { Point(), Vector(), 0, 0 };
    Color lcolor;
    light->generateLightRay(in.localGeo, &lray, &lcolor);
    if (!primitive.intersectP(lray)) {
      Color tempColor = *color;
      Color shade = shading(ray, &in.localGeo, &brdf, lray, &lcolor);
      *color = tempColor + shade;
    }
  }

  if (brdf.ks.r > 0 || brdf.ks.g > 0 || brdf.ks.b > 0) {
    Ray reflectRay = createReflectRay(in.localGeo, ray);
    Color reflectColor = Color();
    trace(reflectRay, depth + 1, &reflectColor);

    Color fadedReflectColor = reflectColor * brdf.ks;
    *color = *color + fadedReflectColor;
  }
}

Color RayTracer::shading(const Ray &eyeRay, LocalGeo *lg, BRDF *brdf, Ray &lray,
    Color *lcolor) {

  float atten = 1.0f;
  // Check if light source is directional by check if if t_max is infinity.
  // If the light source is a point light, then calculate the attentuation,
  // otherwise use an attenuation of 1.
  if (lray.t_max < std::numeric_limits<float>::infinity()) {
    atten = brdf->atten.calc(lray.t_max);
  }
  Color lightColor = *lcolor;

  // Need to calculate dot products with normalized direction.
  Vector lightDir = lray.dir.normalize();
  Normal objNormal = lg->normal;

  // Lambert calculation for diffuse term
  Color kd = brdf->kd;
  float nDotL = objNormal.dot(lightDir);
  Color lambert = kd * lightColor * std::max(nDotL, 0.0f);

  // Phong calculation for specular term.
  Vector eyeDirn = (eyeRay.pos - lg->pos).normalize();
  Vector halfVec = (lray.dir + eyeDirn).normalize();
  float nDotH = objNormal.dot(halfVec);
  Color ks = brdf->ks;
  float shininess = brdf->shininess;
  Color phong = ks * lightColor * pow(std::max(nDotH, 0.0f), shininess);

  return (lambert + phong) * atten;
}

Ray RayTracer::createReflectRay(LocalGeo &lg, const Ray &ray) {
  float epsilon = 0.0001f;
  // ray.dir is negated for dot product because it is directed *toward* the
  // local geometry.
  float lDotN = -ray.dir.dot(lg.normal);

  // Don't negate ray.dir here for the same reason stated above.
  Ray reflect = { lg.pos, (ray.dir + lg.normal * 2 * lDotN).normalize(),
      epsilon, std::numeric_limits<float>::infinity() };
  return reflect;
}
