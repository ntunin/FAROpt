#pragma once
#include "Complex.h"
#include "ComplexVector.h"
#include "ComplexVectorT.h"

class ComplexMatrix
{
public:
	ComplexMatrix(int);
	ComplexMatrix(int, int);
	ComplexMatrix(int, int, Complex*);
	ComplexMatrix(int,  Complex*);
	ComplexMatrix(ComplexVector);
	ComplexMatrix& inverse();
	ComplexMatrix& operator-(ComplexMatrix);
	ComplexMatrix& operator+(ComplexMatrix);
	ComplexMatrix& operator*(ComplexMatrix);
	ComplexVector& operator*(ComplexVector);
	ComplexMatrix& operator*(Complex);
	ComplexMatrix& econj();
	double **doubleExtend();
	Complex*& operator[](int);
	int length();
	int width();
	~ComplexMatrix();
private:
	int _n;
	int _m;
	Complex **_matrix;
};

