#include "Integral.h"

long double approxIntegral(long double a , long double b, std::function<long double(long double)> funct) {
	
	if (a > b) 
		return -1 * approxIntegral(b, a, funct);
	if (a == b) 
		return 0.0;
	// use Riemann Sum mid point
	long double rollingSum = 0.0;
	Timer timer;
	timer.start();
	long double t = a;
	long double tBefore = a;
	while (t <= b) {
		t = a + timer.getTime();
		long double xi = (t + tBefore) / 2.0;
		long double dt = t - tBefore;
		rollingSum += funct(xi) * dt;
		tBefore = t;
	}
	return rollingSum;
}
