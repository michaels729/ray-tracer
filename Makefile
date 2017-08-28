CXX =	g++

CXXFLAGS =	-O3 -Wall -fmessage-length=0 -fno-strict-aliasing -fopenmp\
-pthread -std=c++11

OBJS =	RayTracer.o Camera.o Scene.o Film.o Sample.o\
Material.o Color.o\
Attenuation.o DirectionalLight.o PointLight.o Light.o\
AggregatePrimitive.o GeometricPrimitive.o Primitive.o\
Sphere.o Triangle.o Shape.o\
Transformation.o Matrix.o

EXECUTABLES = loadscene TestTransformation TestMatrix

INCLUDES=	-I ./third-party/include/eigen

LIBS =	-lfreeimage

TARGET =	loadscene

PNG = 	*.png

$(TARGET):	$(OBJS)
	$(CXX) $(INCLUDES) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

loadscene:	$(OBJS)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o loadscene $(OBJS) loadscene.cpp $(LIBS)

TestTransformation:	Transformation.o Matrix.o
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o TestTransformation Transformation.o Matrix.o geo/TestTransformation.cpp

TestMatrix:	Matrix.o
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o TestMatrix Matrix.o geo/TestMatrix.cpp

RayTracer.o:	RayTracer.cpp RayTracer.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c RayTracer.cpp

Camera.o:	Camera.cpp Camera.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c Camera.cpp

Scene.o:	Scene.cpp Scene.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c Scene.cpp

Film.o:	Film.cpp Film.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c Film.cpp

Sample.o:	Sample.cpp Sample.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c Sample.cpp

Material.o:	color/Material.cpp color/Material.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c color/Material.cpp

Color.o:	color/Color.cpp color/Color.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c color/Color.cpp

Attenuation.o:	light/Attenuation.cpp light/Attenuation.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c light/Attenuation.cpp

DirectionalLight.o:	light/DirectionalLight.cpp light/DirectionalLight.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c light/DirectionalLight.cpp

PointLight.o:	light/PointLight.cpp light/PointLight.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c light/PointLight.cpp

Light.o:	light/Light.cpp light/Light.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c light/Light.cpp

AggregatePrimitive.o:	geo/AggregatePrimitive.cpp geo/AggregatePrimitive.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/AggregatePrimitive.cpp

GeometricPrimitive.o:	geo/GeometricPrimitive.cpp geo/GeometricPrimitive.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/GeometricPrimitive.cpp

Primitive.o:	geo/Primitive.cpp geo/Primitive.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/Primitive.cpp

Sphere.o:	geo/Sphere.cpp geo/Sphere.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/Sphere.cpp

Triangle.o:	geo/Triangle.cpp geo/Triangle.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/Triangle.cpp

Shape.o:	geo/Shape.cpp geo/Shape.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/Shape.cpp

Ray.o:	geo/Ray.cpp geo/Ray.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/Ray.cpp

Transformation.o:	geo/Transformation.cpp geo/Transformation.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/Transformation.cpp

Matrix.o:	geo/Matrix.cpp geo/Matrix.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c geo/Matrix.cpp

clean:
	rm -f $(OBJS) $(EXECUTABLES) $(TARGET) $(PNG)
