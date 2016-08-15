#include "matrix.h"
#include <stdio.h>

int main(int argc, const char** argv) {
	printf("Matrix Test\n");
	
	Matrix* A = new Matrix(3, 3);
	A->put(0,0,3.0);
	A->put(0,1,4.0);
	A->put(0,2,9.0);
	A->put(1,0,-4.0);
	A->put(1,1,3.0);
	A->put(1,2,6.0);
	A->put(2,0,3.0);
	A->put(2,1,-7.0);
	A->put(2,2,8.0);	
	Matrix* B = new Matrix(2, 2);
	B->put(0,0,5.0);
	B->put(0,1,-3.0);
	B->put(1,0,2.0);
	B->put(1,1,4.0);
	A->print();
	B->print();
	
	printf("time to kronecker\n");
	Matrix* kroneck = Matrix::kronecker_product(A, B);
	kroneck-> print();
	delete kroneck;	
	delete A;
	delete B;
	return 0;

}
