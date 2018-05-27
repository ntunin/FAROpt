#include "stdafx.h"
#include "ComplexVector.h"


ComplexVector::ComplexVector() {
	this->_n = 0;
	this->_ComplexVector = new Complex[0];
}

ComplexVector::ComplexVector(int n) {
	this->_n = n;
	this->_ComplexVector = new Complex[n];
}

ComplexVector::ComplexVector(int n, Complex *ComplexVector) {
	this->_n = n;
	this->_ComplexVector = new Complex[n];
	for (int i = 0; i < n; i++) {
		this->_ComplexVector[i] = ComplexVector[i];
	}
}


ComplexVector::~ComplexVector()
{
	delete[] this->_ComplexVector;
}

int ComplexVector::length() {
	return this->_n;
}

Complex& ComplexVector::operator[](int i) {
	return this->_ComplexVector[i];
}

ComplexVectorT& ComplexVector::econj() {
	ComplexVectorT v = ComplexVectorT(this->_n);
	for (int i = 0; i < this->_n; i++) {
		v[i] = this->_ComplexVector[i].conj();
	}
	return v;
}

ComplexVectorT& ComplexVector::T() {
	return *(new ComplexVectorT(this->_n, this->_ComplexVector));
}


double *ComplexVector::extendDouble() {
	double *res = new double[2 * this->_n];
	for (int i = 0; i < this->_n; i++) {
		res[i] = this->_ComplexVector[i].Re();
		res[i + this->_n] = this->_ComplexVector[i].Im();
	}
	return res;
}
