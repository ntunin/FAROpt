#include "stdafx.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

using namespace std;

OneLimitDirectivityOptimisationAlgoritm::~OneLimitDirectivityOptimisationAlgoritm() {
}

OneLimitDirectivityOptimisationAlgoritm::OneLimitDirectivityOptimisationAlgoritm() {

}

double **OneLimitDirectivityOptimisationAlgoritm::calculateB(OptimisationEnvirounment *envirounment) {
	int N = envirounment->getSourceCount();
	NecIn *in = envirounment->getIn();
	RP *rp = in->getRP();
	int thetaNumber = rp->getThetaNumber();
	int phiNumber = rp->getPhiNumber();
	Complex ****A = envirounment->getA();
	ComplexMatrix complexB = ComplexMatrix(N);
	double divider = 180 / rp->getPhiInc();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Complex summ;
			for (int k = 0; k < thetaNumber; k++) {
				double m = (k == thetaNumber - 1) ? 0.5 : 1;
				for (int l = 0; l < phiNumber; l++) {
					Complex a = A[i][j][k][l] * sin(PI * k / divider);
					a = a * m;
					summ += a;
				}
			}
			complexB[i][j] = summ;
		}
	}
	return complexB.doubleExtend();
}

double *OneLimitDirectivityOptimisationAlgoritm::getInitial(OptimisationEnvirounment *envirounment) {
	FAROptimisationAlgoritm *algoritm = new LamdaDirectivityOptimisationAlgoritm(envirounment);
	return algoritm->getV()->extendDouble();
}

