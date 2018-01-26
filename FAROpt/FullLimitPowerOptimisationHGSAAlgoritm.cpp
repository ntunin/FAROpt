#include "stdafx.h"
#include "FullLimitPowerOptimisationHGSAAlgoritm.h"

using namespace std;

FullLimitPowerOptimisationHGSAAlgoritm::FullLimitPowerOptimisationHGSAAlgoritm(OptimisationEnvirounment *envirounment, vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree) {
	this->P = P;
	this->TInitial = T;
	this->coolDownSpeed = coolDownSpeed;
	this->radius = radius;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->solveFullLimitOptimisationTask(envirounment);
}

void FullLimitPowerOptimisationHGSAAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
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


double FullLimitPowerOptimisationHGSAAlgoritm::targetFunction(double *x) {
	double uAu = this->calculate_uAu(x);
	vector<double> *uBu = this->calculate_uBu(x);
	int M = uBu->size();
	double s = 0;
	for (int i = 0; i < M; i++) {
		double uBui = (*uBu)[i];
		s += pow(abs(min(uBui, 0) + max(uBui, 1)), this->mulctDegree);
	}
	delete uBu;
	return uAu - this->mulctMultiplier * s;
}


FullLimitPowerOptimisationHGSAAlgoritm::~FullLimitPowerOptimisationHGSAAlgoritm()
{
}
