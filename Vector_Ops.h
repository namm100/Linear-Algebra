#include <vector>
#include <iostream>
#include <functional>
#include "Derivative.h"

#ifndef VECTOR_OPS_H
#define VECTOR_OPS_H


// 2D vector field of i and j
//E(x,y) = <f(x,y),g(x,y)>
// divergence of E
long double divergence(long double x, long double y, std::vector<funct2> E);

std::vector<long double> curl(long double x,long double y, long double z, std::vector<funct3> E);

void printVector(std::vector<long double> A);
#endif

