CC=g++

CFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		raytracer.o Vector.o Matrix.o

LIBS =

TARGET =	raytracer

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

Matrix:	Matrix.o Vector.o
	$(CC) $(CFLAGS) -o Matrix Matrix.o Vector.o

Matrix.o:	matrix/Matrix.cpp matrix/Matrix.h
	$(CC) $(CFLAGS) -c matrix/Matrix.cpp

Vector.o:	geo/Vector.cpp geo/Vector.h
	$(CC) $(CFLAGS) -c geo/Vector.cpp

clean:
	rm -f $(OBJS) $(TARGET)
