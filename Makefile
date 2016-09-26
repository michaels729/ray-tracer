CXX =	g++

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -fno-strict-aliasing -pthread -std=c++11

OBJS =	Scene.o Film.o Sampler.o Sample.o Color.o

EXECUTABLES = Scene

LIBS =	-lfreeimage

TARGET =	RayTracer

PNG = 	*.png

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

Scene:	$(OBJS)
	$(CXX) $(CXXFLAGS) -o Scene $(OBJS) $(LIBS)

Scene.o:	Scene.cpp Scene.h
	$(CXX) $(CXXFLAGS) -c Scene.cpp

Film.o:	Film.cpp Film.h
	$(CXX) $(CXXFLAGS) -c Film.cpp

Sampler.o:	Sampler.cpp Sampler.h
	$(CXX) $(CXXFLAGS) -c Sampler.cpp

Sample.o:	Sample.cpp Sample.h
	$(CXX) $(CXXFLAGS) -c Sample.cpp

Color.o:	color/Color.cpp color/Color.h
	$(CXX) $(CXXFLAGS) -c color/Color.cpp

Matrix:	Matrix.o Vector.o
	$(CXX) $(CXXFLAGS) -o Matrix Matrix.o Vector.o

Matrix.o:	geo/Matrix.cpp geo/Matrix.h
	$(CXX) $(CXXFLAGS) -c geo/Matrix.cpp

Vector.o:	geo/Vector.cpp geo/Vector.h
	$(CXX) $(CXXFLAGS) -c geo/Vector.cpp

Point.o:	geo/Point.cpp geo/Point.h
	$(CXX) $(CXXFLAGS) -c geo/Point.cpp

clean:
	rm -f $(OBJS) $(EXECUTABLES) $(TARGET) $(PNG)
