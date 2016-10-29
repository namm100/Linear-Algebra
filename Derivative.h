#include "Timer.h"
#include <functional>
#include <math.h>
#include <vector>

#ifndef DERIVATIVE_H
#define DERIVATIVE_H

typedef std::function<long double(long double)> funct1;
typedef std::function<long double(long double, long double)> funct2;
typedef std::function<long double(long double, long double, long double)> funct3;

//single variable function f(t)
long double approxDeriv(long double t, std::function<long double(long double)> funct);

//double variable function f(x,y)
long double approxDeriv(char respect, long double x, long double y, std::function<long double(long double, long double)> z);
std::vector<long double> approxGradient(long double x, long double y, std::function<long double(long double, long double)> funct);

//triple variable function f(x,y,z)
long double approxDeriv(char respect, long double x, long double y, long double z, std::function<long double(long double, long double, long double)> f);
std::vector<long double> approxGradient(long double x, long double y, long double z, std::function<long double(long double, long double, long double)> f);

#endif /* DERIVATIVE_H */
