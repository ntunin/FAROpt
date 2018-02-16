#include "stdafx.h"
#include "OneLimitGradientOptimisationAlgoritm.h"

using namespace std;

OneLimitGradientOptimisationAlgoritm::OneLimitGradientOptimisationAlgoritm(OptimisationEnvirounment *envirounment, double mulctMultiplier, double mulctDegree) {
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->solveOneLimitOptimisationTask(envirounment);
}

void OneLimitGradientOptimisationAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
	NecIn *in = envirounment->getIn();
	int sourceCount = envirounment->getSourceCount();
	this->vEx = this->getInitial(envirounment);
	this->setInitial(vEx);
	this->makeMaximisational();
	this->setSize(sourceCount * 2);
	this->solve();
}

double OneLimitGradientOptimisationAlgoritm::targetFunction(double *x) {
	double uAu = this->calculate_uAu(x);
	double uBu = this->calculate_uBu(x);
	double s = pow(abs(min(uBu, 0) + max(uBu, 1)), this->mulctDegree);
	return uAu - this->mulctMultiplier * s;
}

void OneLimitGradientOptimisationAlgoritm::getGradient(double *x, double *dF, int size) {
	double *duAu = new double[size];
	Utils::gradient(size, this->AEx, x, duAu);
	double uBu = this->calculate_uBu(x);
	double *duBu = new double[size];
	if (uBu >= 0 && uBu <= 1) {
		Utils::fill(size, 0, duBu);
	} else {
		int uno = (uBu > 1) ? -1 : 0;
		double m = mulctMultiplier * (uBu + uno) * pow(abs(uBu + uno), mulctDegree - 2);
		Utils::gradient(size, B, x, duBu);
		Utils::mul(size, duBu, m, duBu);
	}
	Utils::summ(size, duAu, duBu, dF);
	delete[] duBu;
	delete[] duAu;
}

OneLimitGradientOptimisationAlgoritm::~OneLimitGradientOptimisationAlgoritm()
{
}
