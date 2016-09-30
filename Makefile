CXX =	g++

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -fno-strict-aliasing -pthread -std=c++11

OBJS =	RayTracer.o Camera.o Sphere.o Scene.o Film.o Sampler.o Sample.o Material.o Color.o Transformation.o Matrix.o Vector.o Point.o

EXECUTABLES = TestSampler TestMatrix

LIBS =	-lfreeimage

TARGET =	RayTracer

PNG = 	*.png

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

TestScene:	$(OBJS)
	$(CXX) $(CXXFLAGS) -o TestScene $(OBJS) TestScene.cpp $(LIBS)

TestSampler:	Sampler.o Sample.o
	$(CXX) $(CXXFLAGS) -o TestSampler Sampler.o Sample.o TestSampler.cpp

TestMatrix:	Matrix.o Vector.o
	$(CXX) $(CXXFLAGS) -o TestMatrix Matrix.o Vector.o geo/TestMatrix.cpp

RayTracer.o:	RayTracer.cpp RayTracer.h
	$(CXX) $(CXXFLAGS) -c RayTracer.cpp

Camera.o:	Camera.cpp Camera.h
	$(CXX) $(CXXFLAGS) -c Camera.cpp

Sphere.o:	geo/Sphere.cpp geo/Sphere.h
	$(CXX) $(CXXFLAGS) -c geo/Sphere.cpp

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

Ray.o:	geo/Ray.cpp geo/Ray.h
	$(CXX) $(CXXFLAGS) -c geo/Ray.cpp

Transformation.o:	geo/Transformation.cpp geo/Transformation.h
	$(CXX) $(CXXFLAGS) -c geo/Transformation.cpp

Matrix.o:	geo/Matrix.cpp geo/Matrix.h
	$(CXX) $(CXXFLAGS) -c geo/Matrix.cpp

Vector.o:	geo/Vector.cpp geo/Vector.h
	$(CXX) $(CXXFLAGS) -c geo/Vector.cpp

Point.o:	geo/Point.cpp geo/Point.h
	$(CXX) $(CXXFLAGS) -c geo/Point.cpp

clean:
	rm -f $(OBJS) $(EXECUTABLES) $(TARGET) $(PNG)
