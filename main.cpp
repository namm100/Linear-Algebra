#include "Vector3.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	Vector3 a(1,2,3);
	Vector3 b(4,5,6);
	Vector3 c = a.cross(b);
	c.print();
	return 0;
}
