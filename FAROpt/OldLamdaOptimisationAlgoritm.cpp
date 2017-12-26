#include "stdafx.h"
#include "OldLamdaOptimisationAlgoritm.h"

OldLamdaOptimisationAlgoritm::OldLamdaOptimisationAlgoritm(OneSourceOptimisationEnvirounment *envirounment) {
	NecIn *in = envirounment->getIn();
	RP *rp = in->getRP();
	double dTheta = rp->getThetaInc() * PI / 180;
	int size = envirounment->getSourceCount();
	int dSize = 2 * size;
	double *Au = new double[dSize];
	ComplexMatrix *complexB = envirounment->getB();
	double **BInverse = complexB->doubleExtend();
	double **B = complexB->doubleExtend();
	double **BSave = complexB->doubleExtend();
	ComplexMatrix Y = *envirounment->getY();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			double y = Y[i][j].Re();
			B[i][j] = y;
			B[i + size][j + size] = y;
			B[i][j + size] = 0;
			B[i + size][j] = 0;
		}
	}



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
			Au[i] += BSave[i][j] * vEx[j];
		}
	}

	double uBu = 0;
	for (int i = 0; i < dSize; i++) {
		uBu += vEx[i] * Au[i];
	}

	ComplexMatrix A = ComplexMatrix(size);
	Complex ****ACover = envirounment->getA();
	int iDirect = envirounment->getIDirect();
	int jDirect = envirounment->getJDirect();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
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
		delete[] BSave[i];
		delete[] AEx[i];
	}
	delete[] Au;
	delete[] B;
	delete[] BSave;
	delete[] BInverse;
	delete[] AEx;
}


OldLamdaOptimisationAlgoritm::~OldLamdaOptimisationAlgoritm()
{
}
