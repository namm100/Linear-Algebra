#include "matrix.h"
#include <stdio.h>
#include <math.h>

Matrix::Matrix(int rows, int cols, double** matrix) {

	(*this).rows = rows;
	(*this).cols = cols;
	(*this).mat = new double*[rows];
	for (int i = 0; i < rows; ++i) {
		(*this).mat[i] = new double[cols];
	}
	
	// set the values of the matrix
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			(*this).mat[i][j] = matrix[i][j];
		}
	}
}

Matrix::Matrix(int rows, int cols) {

	(*this).rows = rows;
	(*this).cols = cols;
	(*this).mat = new double*[rows];
	for (int i = 0; i < rows; ++i) {
		(*this).mat[i] = new double[cols];
	}
	// might want to init each value as a 0
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++)
			(*this).mat[i][j] = 0.0;
}

void Matrix::put(int row, int col, double val) {
	if (row > (*this).rows - 1 || col > (*this).cols - 1) {
		printf("row:%d col:%d is out of bounds\n", row, col);		
		return;
	}
	(*this).mat[row][col] = val;
}
	
double Matrix::at(int row, int col) {
	if (row > (*this).rows - 1 || col > (*this).cols - 1) {
		printf("row:%d col:%d is out of bounds\n", row, col);
		return -1;
	}
	return (*this).mat[row][col];
}

int Matrix::get_rows() {
	return (*this).rows;
}

int Matrix::get_cols() {
	return (*this).cols;
}

Matrix* Matrix::T()  {
	double** n = new double*[(*this).cols];
	for (int i = 0; i < (*this).cols; i++) {
		n[i] = new double[(*this).rows];
	}
	for (int i = 0; i < (*this).cols; i++) {
		for (int j = 0; j < (*this).rows; j++) {
			n[i][j] = (*this).mat[j][i];
		}
	}
	return new Matrix((*this).cols, (*this).rows, n);
}


void Matrix::print() {
	
	printf("Row:%d Col%d\n", (*this).rows, (*this).cols);
	for (int i = 0; i < (*this).rows; i++) {
		for(int j = 0; j < (*this).cols; j++) {
			double here = (*this).mat[i][j];
			if (fabs(here) < 10) {
				printf("0%f ", here);
			} else {
				printf("%f ", here);
			}
		}
		printf("\n");
	}
} 

bool Matrix::same_dim(Matrix* A, Matrix* B) {
	return (A->get_rows() == B->get_rows() && A->get_cols() == B->get_cols());
}
	
Matrix* Matrix::add(Matrix* A, Matrix*B) {
	if (Matrix::same_dim(A, B)) {
		
		Matrix* toSend = new  Matrix(A->get_rows(), A->get_cols());
		for (int i = 0; i < A->get_rows(); i++) {
			for (int j = 0; j < A->get_cols(); j++) {
				toSend->put(i, j, A->at(i, j) + B->at(i, j));
			}
		}
		return toSend;
	}	
	printf("Dimensions don't match!");	
	return NULL;
}

Matrix* Matrix::multiply(Matrix* A, double k) {
	Matrix* toSend = new Matrix(A->get_rows(), A->get_cols());
	for (int i = 0; i < A->get_rows(); i++) {
		for (int j = 0; j < A->get_cols(); j++) {
			toSend->put(i, j, k * A->at(i, j));
		}
	}
	return toSend;
}

Matrix* Matrix::multiply(double k, Matrix* A) {
	return Matrix::multiply(A, k);
}

Matrix* Matrix::multiply(Matrix* A, Matrix* B) {
	if (Matrix::same_dim(A,B)) {
		Matrix* toSend = new Matrix(A->get_rows(), A->get_cols());
		for (int i = 0; i < A->get_rows(); i++) {
			for (int j = 0; j < A->get_cols(); j++) {
				toSend->put(i, j, A->at(i,j) * B->at(i,j));
			}
		}
		return toSend;
	}
	printf("Dimensions don't match!");
	return NULL;
}	

Matrix* Matrix::dot(Matrix* A, Matrix* B) {
	if (A->get_cols() == B->get_rows()) {
		Matrix* toSend = new Matrix(A->get_rows(), B->get_cols());
		
		for (int i = 0; i < toSend->get_rows(); i++) {
			double* curr_row = new double[A->get_cols()];
			for (int j = 0; j < A->get_cols(); j++) 
				curr_row[j] = A->at(i, j);
			
			for (int j = 0; j < toSend->get_cols(); j++) {

				double* curr_col = new double[B->get_rows()];
				for (int k = 0; k < B->get_rows(); k++)
					curr_col[k] = B->at(k,j);
				double result = Matrix::vectorDot(B->get_rows(), curr_row, curr_col);
				toSend->put(i, j, result);
				delete[] curr_col;
			}
			delete[] curr_row;
		}
		return toSend;
	}
	printf("Dimensions don't match!");
	return NULL;
}

Matrix* Matrix::horizcat(Matrix* A, Matrix* B) { 
	if (A == NULL) {
		return B;
	}
	if (B == NULL) {
		return A;
	}
	
	if (A->get_rows() == B->get_rows()) {
			Matrix* toSend = new Matrix(A->get_rows(), A->get_cols() + B->get_cols());
		// add the A values
		for (int i = 0; i < A->get_rows(); i++) {
			for (int j = 0; j < A->get_cols(); j++) {
				toSend->put(i, j, A->at(i,j));	
			}
		}
		// add the B values
		for (int i = 0; i < B->get_rows(); i++) {
			for (int j = 0; j < B->get_cols(); j++) {
				toSend->put(i, j + A->get_cols(), B->at(i,j));
			}		
		}
		return toSend;
	}
	printf("Dimensions don't match!");
	return NULL;
}
 
Matrix* Matrix::verticat(Matrix* A, Matrix* B) {

	if (A == NULL) {
		return B;
	}
	if (B == NULL) {
		return A;
	}
	
	if (A->get_cols() == B->get_cols()) {

		Matrix* toSend = new Matrix(A->get_rows() + B->get_rows(), A->get_cols());
		// add the A values
		for (int i = 0; i < A->get_rows(); i++) {
			for (int j = 0; j < A->get_cols(); j++) {
				toSend->put(i, j, A->at(i,j));	
			}
		}
		// add the B values

		for (int i = 0; i < B->get_rows(); i++) {
			for (int j = 0; j < B->get_cols(); j++) {
				toSend->put(i + A->get_rows(), j, B->at(i,j));
			}		
		}
		return toSend;	

	}
	printf("Dimensions don't match!");
	return NULL;		
}

void Matrix::print2DArrMat(int rows, int cols, Matrix*** A) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("in 2darrmatprint i:%d j:%d\n",i,j);
			Matrix* curr = A[i][j];
			curr->print();
			delete curr;
		}
	}

}


Matrix* Matrix::smush_horiz(int size, Matrix** A) {
	Matrix* S = NULL;
	for (int i = 0; i < size; i++) {
		S = Matrix::horizcat(S, A[i]); 
	}
	return S; // temp
}

Matrix* Matrix::smush_verti(int size, Matrix** A) {
	Matrix* S = NULL;
	for (int i = 0; i < size; i++) {
		S = Matrix::verticat(S, A[i]);
	}
	return S;
}

void Matrix::printArrMat(int len, Matrix** A) {
	for (int i = 0; i < len; i++)
		A[i]->print();
}
Matrix* Matrix::kronecker_product(Matrix* A, Matrix* B) {

	// init the 2D Array Matrix that holds the values	
	Matrix*** res = new Matrix** [A->get_rows()];
	for (int i =0; i < A->get_rows(); i++) {
		res[i] = new Matrix*[A->get_cols()];
	}
	
	//preform the operaton
	for (int i = 0; i < A->get_rows(); i++) {
		for (int j = 0; j < A->get_cols(); j++) {
			res[i][j] = Matrix::multiply(A->at(i,j), B);
		}
	}
	//Matrix::print2DArrMat(A->get_rows(), A->get_cols(), res);
	Matrix** smush_horiz_res = new Matrix* [A->get_rows()];
	for (int i = 0; i < A->get_rows(); i++) {
		smush_horiz_res[i] = Matrix::smush_horiz(A->get_cols(), res[i]);
	}
	Matrix* smush_vertic_res = Matrix::smush_verti(A->get_rows(), smush_horiz_res);

	
	delete[] res;
	delete[] smush_horiz_res;
	
	return smush_vertic_res;
}


double Matrix::vectorDot(int size, double* A, double* B) {
	double sum = 0;
				
	for (int i = 0; i < size; i++) {
		sum += A[i] * B[i];
	}
	return sum;
}

void Matrix::printArr(int size, double* A) {
	printf("< ");
	for (int i = 0; i < size; i++) 
		printf("%f ", A[i]);
	printf(">\n");
}

Matrix* Matrix::I(int dim) { 
	Matrix* toSend = new Matrix(dim, dim);
	for (int i = 0; i < dim; i++) {
		toSend->put(i,i,1.0);
	}
	return toSend;
}


Matrix::~Matrix() {
	delete[] mat;
}
