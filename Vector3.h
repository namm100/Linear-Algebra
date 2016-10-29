#include <string>
#include <iostream>
#ifndef Vector3_CPP
#define Vector3_CPP

class Vector3 {

public:
	double x,y,z;
	Vector3();
	Vector3(double,double,double);
	Vector3 operator+(Vector3);
	Vector3 operator-(Vector3);
	Vector3 operator*(double);
	double operator*(Vector3);
	Vector3 cross(Vector3);
	void print();
};

#endif
