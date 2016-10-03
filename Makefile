CXX =	g++

CXXFLAGS =	-g -Wall -fmessage-length=0 -fno-strict-aliasing -pthread -std=c++11

OBJS =	RayTracer.o Camera.o Scene.o Film.o Sampler.o Sample.o\
Material.o Color.o\
DirectionalLight.o PointLight.o Light.o\
AggregatePrimitive.o GeometricPrimitive.o Primitive.o\
Sphere.o Triangle.o Shape.o\
Transformation.o Matrix.o Normal.o Vector.o Point.o

EXECUTABLES = TestSampler TestMatrix

LIBS =	-lfreeimage

TARGET =	loadscene

PNG = 	*.png

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

loadscene:	$(OBJS)
	$(CXX) $(CXXFLAGS) -o loadscene $(OBJS) loadscene.cpp $(LIBS)

TestSampler:	Sampler.o Sample.o
	$(CXX) $(CXXFLAGS) -o TestSampler Sampler.o Sample.o TestSampler.cpp

TestMatrix:	Matrix.o Vector.o
	$(CXX) $(CXXFLAGS) -o TestMatrix Matrix.o Vector.o geo/TestMatrix.cpp

RayTracer.o:	RayTracer.cpp RayTracer.h
	$(CXX) $(CXXFLAGS) -c RayTracer.cpp

Camera.o:	Camera.cpp Camera.h
	$(CXX) $(CXXFLAGS) -c Camera.cpp

Scene.o:	Scene.cpp Scene.h
	$(CXX) $(CXXFLAGS) -c Scene.cpp

Film.o:	Film.cpp Film.h
	$(CXX) $(CXXFLAGS) -c Film.cpp

Sampler.o:	Sampler.cpp Sampler.h
	$(CXX) $(CXXFLAGS) -c Sampler.cpp

Sample.o:	Sample.cpp Sample.h
	$(CXX) $(CXXFLAGS) -c Sample.cpp

Material.o:	color/Material.cpp color/Material.h
	$(CXX) $(CXXFLAGS) -c color/Material.cpp

Color.o:	color/Color.cpp color/Color.h
	$(CXX) $(CXXFLAGS) -c color/Color.cpp

DirectionalLight.o:	light/DirectionalLight.cpp light/DirectionalLight.h
	$(CXX) $(CXXFLAGS) -c light/DirectionalLight.cpp

PointLight.o:	light/PointLight.cpp light/PointLight.h
	$(CXX) $(CXXFLAGS) -c light/PointLight.cpp

Light.o:	light/Light.cpp light/Light.h
	$(CXX) $(CXXFLAGS) -c light/Light.cpp

AggregatePrimitive.o:	geo/AggregatePrimitive.cpp geo/AggregatePrimitive.h
	$(CXX) $(CXXFLAGS) -c geo/AggregatePrimitive.cpp

GeometricPrimitive.o:	geo/GeometricPrimitive.cpp geo/GeometricPrimitive.h
	$(CXX) $(CXXFLAGS) -c geo/GeometricPrimitive.cpp

Primitive.o:	geo/Primitive.cpp geo/Primitive.h
	$(CXX) $(CXXFLAGS) -c geo/Primitive.cpp

Sphere.o:	geo/Sphere.cpp geo/Sphere.h
	$(CXX) $(CXXFLAGS) -c geo/Sphere.cpp

Triangle.o:	geo/Triangle.cpp geo/Triangle.h
	$(CXX) $(CXXFLAGS) -c geo/Triangle.cpp

Shape.o:	geo/Shape.cpp geo/Shape.h
	$(CXX) $(CXXFLAGS) -c geo/Shape.cpp

Ray.o:	geo/Ray.cpp geo/Ray.h
	$(CXX) $(CXXFLAGS) -c geo/Ray.cpp

Transformation.o:	geo/Transformation.cpp geo/Transformation.h
	$(CXX) $(CXXFLAGS) -c geo/Transformation.cpp

Matrix.o:	geo/Matrix.cpp geo/Matrix.h
	$(CXX) $(CXXFLAGS) -c geo/Matrix.cpp

Normal.o:	geo/Normal.cpp geo/Normal.h
	$(CXX) $(CXXFLAGS) -c geo/Normal.cpp

Vector.o:	geo/Vector.cpp geo/Vector.h
	$(CXX) $(CXXFLAGS) -c geo/Vector.cpp

Point.o:	geo/Point.cpp geo/Point.h
	$(CXX) $(CXXFLAGS) -c geo/Point.cpp

clean:
	rm -f $(OBJS) $(EXECUTABLES) $(TARGET) $(PNG)
