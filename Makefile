CC=g++

CFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		*.o

EXECUTABLES = Film Sampler Matrix

LIBS = -lpng

TARGET =	RayTracer

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

Film:	Film.o Color.o Sampler.o Sample.o
	$(CC) $(CFLAGS) $(LIBS) -o Film Film.o Color.o Sampler.o Sample.o

Film.o:	Film.cpp Film.h
	$(CC) $(CFLAGS) -c Film.cpp

Sampler:	Sampler.o Sample.o
	$(CC) $(CFLAGS) -o Sampler Sampler.o Sample.o

Sampler.o:	Sampler.cpp Sampler.h
	$(CC) $(CFLAGS) -c Sampler.cpp

Sample.o:	Sample.cpp Sample.h
	$(CC) $(CFLAGS) -c Sample.cpp

Color.o:	color/Color.cpp color/Color.h
	$(CC) $(CFLAGS) -c color/Color.cpp

Matrix:	Matrix.o Vector.o
	$(CC) $(CFLAGS) -o Matrix Matrix.o Vector.o

Matrix.o:	geo/Matrix.cpp geo/Matrix.h
	$(CC) $(CFLAGS) -c geo/Matrix.cpp

Vector.o:	geo/Vector.cpp geo/Vector.h
	$(CC) $(CFLAGS) -c geo/Vector.cpp

clean:
	rm -f $(OBJS) $(EXECUTABLES) $(TARGET)
