#include "stdafx.h"
#include "NewLamdaOptimisationAlgoritm.h"

NewLamdaOptimisationAlgoritm::NewLamdaOptimisationAlgoritm(OneSourceOptimisationEnvirounment *envirounment) {
	NecIn *in = envirounment->getIn();
	RP *rp = in->getRP();
	double dTheta = rp->getThetaInc() * PI / 180;
	int sourceCount = envirounment->getSourceCount();
	int dSize = 2 * sourceCount;
	double *Au = new double[dSize];
	ComplexMatrix *complexB = envirounment->getB();
	double **B = complexB->doubleExtend();
	double **BInverse = complexB->doubleExtend(); //Just need same size, values no metter
	Utils::inverse(dSize, B, BInverse);

	double *vEx = new double[dSize];
	double *gEx = envirounment->getGEx();

	for (int i = 0; i < dSize; i++) {
		vEx[i] = 0;
		for (int j = 0; j < dSize; j++) {
			vEx[i] += BInverse[i][j] * gEx[j];
		}
	}


	for (int i = 0; i < dSize; i++) {
		Au[i] = 0;
		for (int j = 0; j < dSize; j++) {
			double b = B[i][j];
			double v = vEx[j];
			double a = b * v;
			Au[i] += B[i][j] * vEx[j];
		}
	}

	double uBu = 0;
	for (int i = 0; i < dSize; i++) {
		uBu += vEx[i] * Au[i];
	}


	Complex ****ACover = envirounment->getA();
	ComplexMatrix A = ComplexMatrix(sourceCount);
	int iDirect = envirounment->getIDirect();
	int jDirect = envirounment->getJDirect();
	for (int i = 0; i < sourceCount; i++) {
		for (int j = 0; j < sourceCount; j++) {
			A[i][j] = ACover[i][j][iDirect][jDirect];
		}
	}

	double **AEx = A.doubleExtend();
	for (int i = 0; i < dSize; i++) {
		Au[i] = 0;
		for (int j = 0; j < dSize; j++) {
			Au[i] += AEx[i][j] * vEx[j];
		}
	}

	double uAu = 0;
	for (int i = 0; i < dSize; i++) {
		uAu += vEx[i] * Au[i];
	}

	double d = 4 * PI*uAu / (uBu * dTheta * dTheta);

	this->setD(d);
	this->set_uAu(uAu);
	this->set_uBu(uBu);
	this->setV(dSize, vEx);

	for (int i = 0; i < dSize; i++) {
		delete[] B[i];
		delete[] BInverse[i];
		delete[] AEx[i];
	}
	delete[] Au;
	delete[] B;
	delete[] BInverse;
	delete[] AEx;
}


NewLamdaOptimisationAlgoritm::~NewLamdaOptimisationAlgoritm()
{
}
