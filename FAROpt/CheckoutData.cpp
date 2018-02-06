#include "stdafx.h"
#include "CheckoutData.h"


CheckoutData::CheckoutData() {
	this->size = 1e6;
}

double **CheckoutData::getA() {
	return A;
}

std::vector<double **> *CheckoutData::getB() {
	return B;
}

double *CheckoutData::getX() {
	return X;
}

void CheckoutData::setA(double **A) {
	this->A = A;
}

void CheckoutData::setB(std::vector<double **> *B) {
	this->B = B;
}

void CheckoutData::setX(double *X) {
	this->X = X;
}

int CheckoutData::getSize() {
	return this->size;
}

void CheckoutData::setSizeIfNotOutOfBound(int size) {
	if (size > 0 && size < this->size) {
		this->size = size;
	}
}

CheckoutData::~CheckoutData()
{
}
