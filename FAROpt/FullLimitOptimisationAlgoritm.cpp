#include "stdafx.h"
#include "FullLimitOptimisationAlgoritm.h"


FullLimitOptimisationAlgoritm::FullLimitOptimisationAlgoritm()
{
}

void FullLimitOptimisationAlgoritm::set_uAu(double uAu) {
	this->uAu = uAu;
}

void FullLimitOptimisationAlgoritm::setD(double d) {
	this->d = d;
}

void FullLimitOptimisationAlgoritm::setV(int n, double *vEx) {
	int size = n / 2;
	ComplexVector *v = new ComplexVector(size);
	for (int i = 0; i < size; i++) {
		(*v)[i] = Complex(vEx[i], vEx[i + size]);
	}
	this->v = v;
}


double FullLimitOptimisationAlgoritm::get_uAu() {
	return this->uAu;
}

double FullLimitOptimisationAlgoritm::getD() {
	return this->d;
}

ComplexVector* FullLimitOptimisationAlgoritm::getV() {
	return this->v;
}

FullLimitOptimisationAlgoritm::~FullLimitOptimisationAlgoritm()
{
}
