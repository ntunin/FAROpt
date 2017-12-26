#include "stdafx.h"
#include "LamdaOptimisationAlgoritm.h"


LamdaOptimisationAlgoritm::LamdaOptimisationAlgoritm() {
}

void LamdaOptimisationAlgoritm::set_uAu(double uAu) {
	this->uAu = uAu;
}

void LamdaOptimisationAlgoritm::set_uBu(double uBu) {
	this->uBu = uBu;
}

void LamdaOptimisationAlgoritm::setD(double d) {
	this->d = d;
}

void LamdaOptimisationAlgoritm::setV(int n, double *vEx) {
	int size = n / 2;
	ComplexVector *v = new ComplexVector(size);
	for (int i = 0; i < size; i++) {
		(*v)[i] = Complex(vEx[i], vEx[i + size]);
	}
	this->v = v;
}


double LamdaOptimisationAlgoritm::get_uAu() {
	return this->uAu;
}

double LamdaOptimisationAlgoritm::get_uBu() {
	return this->uBu;
}

double LamdaOptimisationAlgoritm::getD() {
	return this->d;
}

ComplexVector* LamdaOptimisationAlgoritm::getV() {
	return this->v;
}

LamdaOptimisationAlgoritm::~LamdaOptimisationAlgoritm()
{
}
