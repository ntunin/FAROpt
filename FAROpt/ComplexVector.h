#pragma once
#include "Complex.h"

class ComplexVectorT;

class ComplexVector
{
public:
	ComplexVector();
	ComplexVector(int);
	ComplexVector(int, Complex *);
	~ComplexVector();
	int length();
	Complex& operator[](int);
	ComplexVectorT& T();
	ComplexVectorT& econj();
	double *extendDouble();
protected:
	int _n;
	Complex *_ComplexVector;
};

