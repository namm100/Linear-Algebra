#include "Vector3.h"

Vector3::Vector3() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector3::Vector3(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

Vector3 Vector3::operator+(Vector3 B) {
	Vector3 C;
	C.x = x + B.x;
	C.y = y + B.y;
	C.z = z + B.z; 
	return C;
}

Vector3 Vector3::operator-(Vector3 B) {
	Vector3 C;
	C.x = x - B.x;
	C.y = y - B.y;
	C.z = z - B.z;
	return C;
}

Vector3 Vector3::operator*(double k) {
	Vector3 C;
	C.x = k * x;
	C.y = k * y;
	C.z = k * z;
	return C;
}

double Vector3::operator*(Vector3 A) {
	double At = x * A.x + y * A.y + z * A.z;
	return At;
}

Vector3 Vector3::cross(Vector3 B) {
	Vector3 C;
	C.x = y * B.z - z * B.y;
	C.y = z * B.x - x * B.z;
	C.z = x * B.y - y * B.x;
	return C;
}

void Vector3::print() {
	std::cout << "<" << x << "," << y << "," << z << ">" << std::endl;
}
