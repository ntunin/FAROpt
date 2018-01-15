#include "stdafx.h"
#include "OneLimitOptimisationEnvirounment.h"
#define PI 3.14159265359

using namespace std;

OneLimitOptimisationEnvirounment::OneLimitOptimisationEnvirounment(NecIn *in, int theta, int phi) {
	this->optimisationEnvirounmentSetup(in, theta, phi);
	this->fillB();
	this->fillGEx();
}

void OneLimitOptimisationEnvirounment::fillB() {
	this->B = new ComplexMatrix(this->sourceCount);
	for (int i = 0; i < this->sourceCount; i++) {
		for (int j = 0; j < this->sourceCount; j++) {
			Complex summ;
			for (int k = 0; k < this->thetaNumber; k++) {
				double m = (k == this->thetaNumber - 1) ? 0.5 : 1;
				for (int l = 0; l < this->phiNumber; l++) {
					Complex a = this->A[i][j][k][l] * sin(PI * k / 36); //Why 36??? 
					a = a * m;
					summ += a;
				}
			}
			(*this->B)[i][j] = summ;
		}
	}

	Shared::bundle().log()->print("\n\nB matrix:\n");
	Shared::bundle().log()->print(*this->B);
}

void OneLimitOptimisationEnvirounment::fillGEx() {
	ComplexVector g = ComplexVector(this->sourceCount);
	int patternNumber = this->thetaNumber * this->jDirect + this->iDirect;
	for (int i = 0; i < this->sourceCount; i++) {
		vector<NecOut::RadiationPattern> rp = this->outs[i]->getRadiationPatterns();
		Complex e = rp[patternNumber].getE().conj();
		g[i] = e;
	}

	this->gEx = g.extendDouble();
}

OneLimitOptimisationEnvirounment::~OneLimitOptimisationEnvirounment()
{
}

ComplexMatrix *OneLimitOptimisationEnvirounment::getB() {
	return this->B;
}


double *OneLimitOptimisationEnvirounment::getGEx() {
	return this->gEx;
}
