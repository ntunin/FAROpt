#include "stdafx.h"
#include "FullLimitPowerOptimisationHGAlgoritm.h"


using namespace std;

FullLimitPowerOptimisationHGAlgoritm::FullLimitPowerOptimisationHGAlgoritm(OptimisationEnvirounment *envirounment, vector<double> *P, double mulctMultiplier, double mulctDegree) {
	this->P = P;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->randomStartRadius = 0;
	this->solveFullLimitOptimisationTask(envirounment);
}

FullLimitPowerOptimisationHGAlgoritm::FullLimitPowerOptimisationHGAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double mulctMultiplier, double mulctDegree, double randomStartRadius) {
	this->P = P;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->randomStartRadius = randomStartRadius;
	this->solveFullLimitOptimisationTask(envirounment);
}

void FullLimitPowerOptimisationHGAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
	int sourceCount = envirounment->getSourceCount();
	this->randomStartRadius = 100;
	if (this->randomStartRadius) {
		this->vEx = new double[sourceCount * 2];
		for (int i = 0; i < sourceCount * 2; i++) {
			int r = Shared::bundle().randomGenerator()->next();
			double v = r % ((int)(2 * randomStartRadius * 1e2)) / 1e2 - randomStartRadius;
			this->vEx[i] = v;
			this->start.push_back(v);
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


double FullLimitPowerOptimisationHGAlgoritm::targetFunction(double *x) {
	double uAu = this->calculate_uAu(x);
	vector<double> *uBu = this->calculate_uBu(x);
	int M = uBu->size();
	double s = 0;
	if (inside) {
		for (int i = 0; i < M; i++) {
			double uBiu = (*uBu)[i];
			s += -1 / (uBiu + 1) + 1 / uBiu;
		}
	}
	else {
		bool flag = true;
		for (int i = 0; i < M; i++) {
			double uBiu = (*uBu)[i];
			flag = flag && (uBiu >= 0 && uBiu <= 1);
			s += -pow(abs(min(uBiu, 0) + max(uBiu, 1)) - 1, this->mulctDegree);
		}
		//inside = flag;
	}
	return uAu + this->mulctMultiplier * s;
}

FullLimitPowerOptimisationHGAlgoritm::~FullLimitPowerOptimisationHGAlgoritm()
{
}
