#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

public: 
	Matrix(int rows, int cols, double** matrix);
	Matrix(int rows, int cols);
	~Matrix();
	void put(int row, int col, double val);
	double at(int row, int col);
	int get_rows();
	int get_cols();

	static Matrix* add(Matrix* A, Matrix* B);
	static Matrix* multiply(Matrix* A, double k);
	static Matrix* multiply(double k, Matrix* A);
	static Matrix* multiply(Matrix* A, Matrix* B);
	static Matrix* dot(Matrix* A, Matrix* B);

	static Matrix* horizcat(Matrix* A, Matrix* B);
	static Matrix* verticat(Matrix* A, Matrix* B);

	static Matrix* kronecker_product(Matrix* A, Matrix* B);
	Matrix* T();
	static double vectorDot(int size, double* A, double* B);
	static void printArr(int size, double* A);
	static Matrix* smush_horiz(int size,Matrix** A);
	static Matrix* smush_verti(int size,Matrix** A);
	static bool same_dim(Matrix* A, Matrix* B);
	
	static void print2DArrMat(int rows, int cols, Matrix*** A);
	static void printArrMat(int len, Matrix** A);
	
	static Matrix* I(int dim);
	
	Matrix* operator+(Matrix* A);
	Matrix* operator-(Matrix* A);
	Matrix* operator*(double k);
	Matrix* operator*(Matrix* A);
	void print();
private:
	int rows, cols;
	double** mat;
	 

protected:


};

#endif
