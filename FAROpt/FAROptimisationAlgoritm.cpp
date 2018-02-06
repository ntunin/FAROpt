#include "stdafx.h"
#include "FAROptimisationAlgoritm.h"


FAROptimisationAlgoritm::FAROptimisationAlgoritm()
{
}


FAROptimisationAlgoritm::~FAROptimisationAlgoritm() {
	delete uBu;
}

std::vector<double> *FAROptimisationAlgoritm::get_uBu() {
	return uBu;
}

void FAROptimisationAlgoritm::set_uBu(std::vector<double> *uBu) {
	this->uBu = uBu;
}

void FAROptimisationAlgoritm::set_uAu(double uAu) {
	this->uAu = uAu;
}

void FAROptimisationAlgoritm::setD(double d) {
	this->d = d;
}

void FAROptimisationAlgoritm::setV(int n, double *vEx) {
	int size = n / 2;
	ComplexVector *v = new ComplexVector(size);
	for (int i = 0; i < size; i++) {
		(*v)[i] = Complex(vEx[i], vEx[i + size]);
	}
	this->v = v;
}


double FAROptimisationAlgoritm::get_uAu() {
	return this->uAu;
}


double FAROptimisationAlgoritm::getD() {
	return this->d;
}

ComplexVector* FAROptimisationAlgoritm::getV() {
	return this->v;
}
