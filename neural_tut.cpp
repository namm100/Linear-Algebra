#include <stdio.h>
#include "Matrix.h"
#include <cmath>

using namespace std;

class NN {

	public:
		NN();
		~NN();
		Matrix* sigmoid(Matrix* A);
		Matrix* sigmoidPrime(Matrix* A);
		double sigmoid_one(double n) {
			return 1 / (1 + exp(-1 * n));
		}
		double sigmoid_prime_one(double n) {
			return exp(n) / pow(exp(n) + 1, 2);
		};
		Matrix* foward(Matrix* X);
		
	
			
};

Matrix* NN::sigmoid(Matrix* A) {
	Matrix* B = new Matrix(A->get_rows(), A->get_cols());
	for (int i = 0; i < (*A).get_rows(); i++) {
		for (int j = 0; j < (*A).get_cols(); j++) {
			double c = sigmoid_one(A->at(i, j));
			B->put(i,j,c);
		}
	}
	return B;
}

Matrix* NN::sigmoid_prime(Matrix* A) {
	Matrix* B = new Matrix(A->get_rows(), A->get_cols());
	for (int i = 0; i < (*A).get_rows(); i++) {
		for (int j = 0; j < (*A).get_cols(); j++) {
			double c = sigmoid_prime_one(A->at(i, j));
			B->put(i,j,c);
		}
	}
	return B;
}
