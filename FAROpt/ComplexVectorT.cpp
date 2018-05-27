#include "stdafx.h"
#include "ComplexVectorT.h"

ComplexVectorT::ComplexVectorT() {
	this->_n = 0;
	this->_ComplexVector = new Complex[0];
}

ComplexVectorT::ComplexVectorT(int n) {
	this->_n = n;
	this->_ComplexVector = new Complex[n];
}

ComplexVectorT::ComplexVectorT(int n, Complex *ComplexVector) {
	this->_n = n;
	this->_ComplexVector = new Complex[n];
	for (int i = 0; i < n; i++) {
		this->_ComplexVector[i] = ComplexVector[i];
	}
}

ComplexVectorT::ComplexVectorT(ComplexVector v) {
	this->_n = v.length();
	this->_ComplexVector = new Complex[this->_n];
	for (int i = 0; i < this->_n; i++) {
		this->_ComplexVector[i] = v[i];
	}
}

Complex& ComplexVectorT::operator[](int i) {
	return this->_ComplexVector[i];
}

Complex& ComplexVectorT::operator*(ComplexVector v) {
	int length = (int)fmin(this->_n, v.length());
	Complex *a = new Complex();
	for (int i = 0; i < length; i++) {
		*a += this->_ComplexVector[i] * v[i];
	};
	return *a;
}


ComplexVectorT& ComplexVectorT::operator*(ComplexMatrix m) {
	int length = (int)fmin(m.length(), this->_n);
	int width = (int)fmin(this->_n, this->_n);
	ComplexVectorT r = ComplexVectorT(length);
	for (int j = 0; j < length; j++) {
		Complex a = Complex();
		for (int i = 0; i < width; i++) {
			a += this->_ComplexVector[i] * m[i][j];
		}
		r[j] = a;
	}
	return r;
}

int ComplexVectorT::length() {
	return this->_n;
}


ComplexVectorT::~ComplexVectorT()
{
	delete this->_ComplexVector;
}
