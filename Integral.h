#include "Timer.h"
#include <functional>

#ifndef INTEGRAL_H
#define INTEGRAL_H

long double approxIntegral(long double a, long double b, std::function<long double(long double)> funct);

#endif /* INTEGRAL_H */
