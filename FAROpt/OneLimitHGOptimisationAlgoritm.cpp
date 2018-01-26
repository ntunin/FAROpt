#include "stdafx.h"
#include "OneLimitHGOptimisationAlgoritm.h"

using namespace std;

OneLimitHGOptimisationAlgoritm::OneLimitHGOptimisationAlgoritm(OptimisationEnvirounment *envirounment) {
	this->solveOneLimitOptimisationTask(envirounment);
}

void OneLimitHGOptimisationAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
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

double OneLimitHGOptimisationAlgoritm::targetFunction(double *x) {
	double uAu = this->calculate_uAu(x);
	double uBu = this->calculate_uBu(x);
	return uAu / uBu;
}

OneLimitHGOptimisationAlgoritm::~OneLimitHGOptimisationAlgoritm()
{
}
