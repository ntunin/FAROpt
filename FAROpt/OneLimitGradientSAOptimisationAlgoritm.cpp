#include "stdafx.h"
#include "OneLimitGradientSAOptimisationAlgoritm.h"

using namespace std;

OneLimitGradientSAOptimisationAlgoritm::OneLimitGradientSAOptimisationAlgoritm(OptimisationEnvirounment *envirounment, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree) {
	this->TInitial = T;
	this->coolDownSpeed = coolDownSpeed;
	this->radius = radius;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->solveOneLimitOptimisationTask(envirounment);
}

void OneLimitGradientSAOptimisationAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
	NecIn *in = envirounment->getIn();
	int sourceCount = envirounment->getSourceCount();
	vector<EX *> *sources = in->getEX();
	for (int i = 0; i < sourceCount; i++) {
		Complex value = (*sources)[i]->getValue();
		this->vEx[i] = value.Re();
		this->vEx[i + sourceCount] = value.Im();
	}

	this->setInitial(vEx);
	this->makeMaximisational();
	this->setSize(sourceCount * 2);
	this->solve();
}

double OneLimitGradientSAOptimisationAlgoritm::targetFunction(double *x) {
	double uAu = this->calculate_uAu(x);
	double uBu = this->calculate_uBu(x);
	double s = pow(abs(min(uBu, 0) + max(uBu, 1)), this->mulctDegree);
	return uAu - this->mulctMultiplier * s;
}

void OneLimitGradientSAOptimisationAlgoritm::getGradient(double *x, double *dF, int size) {
	double uBu = this->calculate_uBu(x);
	if (uBu >= 0 && uBu <= 1) {
		Utils::fill(size, 0, dF);
		return;
	}
	int uno = (uBu > 1) ? -1 : 0;
	double m = mulctMultiplier * mulctDegree * (uBu + uno) * pow(abs(uBu + uno), mulctDegree - 2);
	double *duBu = new double[size];
	Utils::gradient(size, B, x, duBu);
	Utils::mul(size, duBu, m, dF);
}


OneLimitGradientSAOptimisationAlgoritm::~OneLimitGradientSAOptimisationAlgoritm()
{
}
