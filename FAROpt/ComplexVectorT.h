#pragma once
#include "Complex.h"
#include "ComplexVector.h"

class ComplexMatrix;

class ComplexVectorT :
	protected ComplexVector
{
public:
	ComplexVectorT();
	ComplexVectorT(int);
	ComplexVectorT(int, Complex *);
	ComplexVectorT(ComplexVector);
	Complex& operator[](int);
	~ComplexVectorT();
	int length();

	ComplexVectorT& operator*(ComplexMatrix);
	Complex operator*(ComplexVector);


};

