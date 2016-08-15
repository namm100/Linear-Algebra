
#ifndef NEURAL_NETWORK_TUT_H
#define NEURAL_NETWORK_TUT_H

class Neural_Network {


public:

	Neural_Network();
	~Neural_Network();
	foward(Matrix* X);
	Matrix* sigmoid(Matrix* Z);
	Matrix* sigmoid_prime(Matrix* Z);
	double cost(Matrix* X, Matrix* Y);
		
private:
i	

};




#endif
