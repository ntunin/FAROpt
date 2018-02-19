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
	this->randomStartRadius = 0;
	this->solveFullLimitOptimisationTask(envirounment);
}

FullLimitPowerOptimisationHGSAAlgoritm::FullLimitPowerOptimisationHGSAAlgoritm(OptimisationEnvirounment *envirounment, vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, double randomStartRadius) {
	this->P = P;
	this->TInitial = T;
	this->coolDownSpeed = coolDownSpeed;
	this->radius = radius;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->randomStartRadius = randomStartRadius;
	this->solveFullLimitOptimisationTask(envirounment);
}

void FullLimitPowerOptimisationHGSAAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
	int sourceCount = envirounment->getSourceCount();
	if (this->randomStartRadius) {
		this->vEx = new double[sourceCount * 2];
		for (int i = 0; i < sourceCount * 2; i++) {
			int r = Shared::bundle().randomGenerator()->next();
			double v = r % ((int)(2 * randomStartRadius * 1e3)) / 1e3 - randomStartRadius;
			this->vEx[i] = v;
		}
	} else {
		this->vEx = FullLimitDirectivityPseudoOptimisationAlgoritm(envirounment, this->P).getV()->extendDouble();
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
		s += pow(abs(min(uBui, 0) + max(uBui, 1)) - 1, this->mulctDegree);
	}
	delete uBu;
	return uAu - this->mulctMultiplier * s;
}


FullLimitPowerOptimisationHGSAAlgoritm::~FullLimitPowerOptimisationHGSAAlgoritm()
{
}
