#include "stdafx.h"
#include "FullLimitPowerOptimisationGradientSAAlgoritm.h"


using namespace std;

FullLimitPowerOptimisationGradientSAAlgoritm::FullLimitPowerOptimisationGradientSAAlgoritm(OptimisationEnvirounment *envirounment, vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree) {
	this->P = P;
	this->TInitial = T;
	this->coolDownSpeed = coolDownSpeed;
	this->radius = radius;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->solveFullLimitOptimisationTask(envirounment);
}

FullLimitPowerOptimisationGradientSAAlgoritm::FullLimitPowerOptimisationGradientSAAlgoritm(OptimisationEnvirounment *envirounment, vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, double randomStartRadius) {
	this->P = P;
	this->TInitial = T;
	this->coolDownSpeed = coolDownSpeed;
	this->radius = radius;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->randomStartRadius = randomStartRadius;
	this->solveFullLimitOptimisationTask(envirounment);
}
void FullLimitPowerOptimisationGradientSAAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
	int sourceCount = envirounment->getSourceCount();
	if (this->randomStartRadius) {
		this->vEx = new double[sourceCount * 2];
		for (int i = 0; i < sourceCount * 2; i++) {
			int r = rand();
			double v = r % ((int)(2 * randomStartRadius * 1e3)) / 1e3 - randomStartRadius;
			this->vEx[i] = v;
		}
	}
	else {
		this->vEx = FullLimitDirectivityPseudoOptimisationAlgoritm(envirounment, this->P).getV()->extendDouble();
	}
	this->setInitial(vEx);
	this->makeMaximisational();
	this->setSize(sourceCount * 2);
	this->solve();
}


double FullLimitPowerOptimisationGradientSAAlgoritm::targetFunction(double *x) {
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


void FullLimitPowerOptimisationGradientSAAlgoritm::getGradient(double *x, double *dF, int size) {
	Utils::fill(size, 0, dF);
	Utils::gradient(size, this->AEx, x, dF);
	vector<double> *uBus = this->calculate_uBu(x);
	for (int i = 0; i < uBus->size(); i++) {
		double *duBu = new double[size];
		double uBu = (*uBus)[i];
		if (uBu >= 0 && uBu <= 1) {
			Utils::fill(size, 0, duBu);
		}
		else {
			int uno = (uBu > 1) ? -1 : 0;
			double m = mulctMultiplier * (uBu + uno) * pow(abs(uBu + uno), mulctDegree - 2);
			double **B = (*this->B)[i];
			Utils::gradient(size, B, x, duBu);
			Utils::mul(size, duBu, m, duBu);
		}
		Utils::summ(size, dF, duBu, dF);
		delete[] duBu;
	}
}



FullLimitPowerOptimisationGradientSAAlgoritm::~FullLimitPowerOptimisationGradientSAAlgoritm()
{
}
