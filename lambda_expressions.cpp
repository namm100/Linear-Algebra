#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include "Vector_Ops.h"
#include "Vector3.h"

using namespace std;

int main(int argc, char** argv) {
	auto f = [] (long double x, long double y) -> long double { return x + pow(y,2.0); };
	auto g = [] (long double x, long double y) -> long double { return x * pow(y, 3.0); };
	std::vector<std::function<long double(long double, long double)>> Ev;
	Ev.push_back(f);
	Ev.push_back(g);
	std::cout << "Ans: " << divergence(4,5,Ev) << std::endl; 
	
	Vector3 a(2,3,4);
	Vector3 b(1,5,6);
	Vector3 c;
	c = a+b;
	
	return 0;
}
