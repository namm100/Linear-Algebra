#include "Derivative.h"

long double approxDeriv(long double t, std::function<long double(long double)> funct) {
	// calc delta T
	Timer ti;
	ti.start();
	long double timeB = 0.0;
	long double timeC = 0.0;
	long double dt = 0.0;
	int n = 2;
	for (int i = 0; i < n; i++) {
		timeC = ti.getTime() + t;
		dt = timeC - timeB;
		//std::cout << "i: " << i << " timeC: " << timeC << " timeB " << timeB << " dt: " << dt << std::endl;
		if (i != n-1)
			timeB = timeC;
	}
	// calc delta F
	long double ff = funct(timeC);
	long double fi = funct(timeB);
	long double df = ff - fi;
	//std::cout << "f(timeC): " << ff << " f(timeB): " << fi << " df: " << df << std::endl;
	long double dfdt = 0.0;
	try {
		dfdt = df / dt;
	} catch (int e) {
		std::cout << "DIVIDE BY 0" << std::endl;
	}
	return dfdt;
}

long double approxDeriv(char respect, long double x, long double y, std::function<long double(long double, long double)> z) {
	if (respect == 'X' or respect == 'x') {
		// calc dz/dx
		auto zx = [y,z] (long double a) -> long double { return z(a,y); };
		return approxDeriv(x, zx);
	} else if (respect == 'Y' or respect == 'y') {
		// calc dz/dy
		auto zy = [x,z] (long double a) -> long double { return z(x,a); };
		return approxDeriv(y, zy);
	} else {
		std::cout << "with respect to what variable?" << std::endl;
		return 0.0;
	}
}

std::vector<long double> approxGradient(long double x, long double y, std::function<long double(long double, long double)> funct) {
	std::vector<long double> toSend { approxDeriv('X', x, y, funct), approxDeriv('Y', x, y, funct) };
	return toSend;
}

long double approxDeriv(char respect, long double x, long double y, long double z, std::function<long double(long double, long double, long double)> f) {
	if (respect == 'X' or respect == 'x') {
		// df/dx
		auto l = [y,z,f] (long double a) -> long double { return f(a,y,z); };
		return approxDeriv(x,l);
	} else if (respect == 'Y' or respect == 'y') {
		// df/dy
		auto l = [x,z,f] (long double a) -> long double { return f(x,a,z); };
		return approxDeriv(y,l);
	} else if (respect == 'Z' or respect == 'z') {
		// df/dz
		auto l = [x,y,f] (long double a) -> long double { return f(x,y,a); };
		return approxDeriv(z,l);
	} else {
		std::cout << "with respect to what variable?" << std::endl;
		return 0.0;
	}	
}

std::vector<long double> approxGradient(long double x, long double y, long double z, std::function<long double(long double, long double, long double)> f) {
	std::vector<long double> toSend {approxDeriv('X', x, y, z, f), approxDeriv('Y', x, y, z, f), approxDeriv('Z', x, y, z, f) };
	return toSend;
}
