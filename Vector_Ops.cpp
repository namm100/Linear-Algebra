#include "Vector_Ops.h"

long double divergence(long double x, long double y, std::vector<funct2> E) {
	return approxDeriv('X', x, y, E.at(0)) + approxDeriv('Y', x, y, E.at(1));	
}

std::vector<long double> curl(long double x, long double y, long double z, std::vector<funct3> E) {
	vector<long double> toSend;
	long double i = approxDeriv('Y',x,y,z,E.at(2)) - approxDeriv('Z',x,y,z,E.at(1));
	long double j = approxDeriv('Z',x,y,z,E.at(0)) - approxDeriv('X',x,y,z,E.at(2));
	long double k = approxDeriv('X',x,y,z,E.at(1)) - approxDeriv('Y',x,y,z,E.at(0));
	toSend.push_back(i);
	toSend.push_back(j);
	toSend.push_back(k);
	return toSend;
}

void printVector(std::vector<long double> A) {
	std::cout << "< ";
	for (int i = 0; i < A.size(); i++)
		std::cout << A.at(i) << " ";
	std::cout << ">\n";
}

