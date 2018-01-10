#include "stdafx.h"
#include "OneLimitOptimisationAlgoritm.h"


OneLimitOptimisationAlgoritm::OneLimitOptimisationAlgoritm() {
}

void OneLimitOptimisationAlgoritm::set_uAu(double uAu) {
	this->uAu = uAu;
}

void OneLimitOptimisationAlgoritm::set_uBu(double uBu) {
	this->uBu = uBu;
}

void OneLimitOptimisationAlgoritm::setD(double d) {
	this->d = d;
}

void OneLimitOptimisationAlgoritm::setV(int n, double *vEx) {
	int size = n / 2;
	ComplexVector *v = new ComplexVector(size);
	for (int i = 0; i < size; i++) {
		(*v)[i] = Complex(vEx[i], vEx[i + size]);
	}
	this->v = v;
}


double OneLimitOptimisationAlgoritm::get_uAu() {
	return this->uAu;
}

double OneLimitOptimisationAlgoritm::get_uBu() {
	return this->uBu;
}

double OneLimitOptimisationAlgoritm::getD() {
	return this->d;
}

ComplexVector* OneLimitOptimisationAlgoritm::getV() {
	return this->v;
}

OneLimitOptimisationAlgoritm::~OneLimitOptimisationAlgoritm()
{
}
