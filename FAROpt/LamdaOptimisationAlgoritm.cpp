#include "stdafx.h"
#include "LamdaOptimisationAlgoritm.h"

using namespace std;

LamdaOptimisationAlgoritm::LamdaOptimisationAlgoritm()
{
}


void LamdaOptimisationAlgoritm::solveLamdaOptimisationTask(OptimisationEnvirounment *envirounment, double *vEx, double **B, int size) {
	int sourceCount = envirounment->getSourceCount();
	NecIn *in = envirounment->getIn();
	int iDirect = envirounment->getIDirect();
	int jDirect = envirounment->getJDirect();
	int thetaNumber = in->getRP()->getThetaNumber();
	ComplexVector g = ComplexVector(sourceCount);
	int patternNumber = thetaNumber * jDirect + iDirect;
	NecOut **outs = envirounment->getOuts();
	for (int i = 0; i < sourceCount; i++) {
		vector<NecOut::RadiationPattern> rp = outs[i]->getRadiationPatterns();
		Complex e = rp[patternNumber].getE().conj();
		g[i] = e;
	}

	double *gEx = g.extendDouble();
	double **BInverse = new double*[size];
	for (int i = 0; i < size; i++) {
		BInverse[i] = new double[size];
	}
	Utils::inverse(size, B, BInverse);

	for (int i = 0; i < size; i++) {
		vEx[i] = 0;
		for (int j = 0; j < size; j++) {
			vEx[i] += BInverse[i][j] * gEx[j];
		}
	}
	for (int i = 0; i < size; i++) {
		delete[] BInverse[i];
	}
	delete BInverse;
	delete gEx;
}


LamdaOptimisationAlgoritm::~LamdaOptimisationAlgoritm()
{
}
