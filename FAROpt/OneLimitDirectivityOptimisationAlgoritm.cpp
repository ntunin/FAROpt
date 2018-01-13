#include "stdafx.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

using namespace std;

OneLimitDirectivityOptimisationAlgoritm::~OneLimitDirectivityOptimisationAlgoritm() {
	delete[] vEx;
}

OneLimitDirectivityOptimisationAlgoritm::OneLimitDirectivityOptimisationAlgoritm() {

}

void OneLimitDirectivityOptimisationAlgoritm::solveDirectivityOptimisationTask(OneLimitOptimisationEnvirounment *envirounment) {
	NecIn *in = envirounment->getIn();
	vector<EX *> *sources = in->getEX();
	RP *rp = in->getRP();
	double dTheta = rp->getThetaInc() * PI / 180;
	int sourceCount = envirounment->getSourceCount();
	this->size = 2 * sourceCount;
	ComplexMatrix *complexB = envirounment->getB();
	this->B = complexB->doubleExtend();
	this->BInverse = complexB->doubleExtend(); //Just need same size, values no metter
	Utils::inverse(size, B, BInverse);

	Complex ****ACover = envirounment->getA();
	ComplexMatrix A = ComplexMatrix(sourceCount);
	int iDirect = envirounment->getIDirect();
	int jDirect = envirounment->getJDirect();
	for (int i = 0; i < sourceCount; i++) {
		for (int j = 0; j < sourceCount; j++) {
			A[i][j] = ACover[i][j][iDirect][jDirect];
		}
	}
	this->AEx = A.doubleExtend();
	vEx = new double[size];
	solveOptimisationTask(envirounment);

	double uAu = calculate_uAu(vEx);
	double uBu = calculate_uBu(vEx);
	double d = 4 * PI*uAu / (uBu * dTheta * dTheta);

	this->setD(d);
	this->set_uAu(uAu);
	this->set_uBu(uBu);
	this->setV(size, vEx);

	for (int i = 0; i < size; i++) {
		delete[] B[i];
		delete[] BInverse[i];
		delete[] AEx[i];
	}
	delete[] B;
	delete[] BInverse;
	delete[] AEx;
}


double OneLimitDirectivityOptimisationAlgoritm::calculate_uBu(double *vEx) {
	double *Bu = new double[size];
	for (int i = 0; i < size; i++) {
		Bu[i] = 0;
		for (int j = 0; j < size; j++) {
			Bu[i] += B[i][j] * vEx[j];
		}
	}
	double uBu = 0;
	for (int i = 0; i < size; i++) {
		uBu += vEx[i] * Bu[i];
	}
	delete[] Bu;
	return uBu;
}

double OneLimitDirectivityOptimisationAlgoritm::calculate_uAu(double *vEx) {
	double *Au = new double[size];
	for (int i = 0; i < size; i++) {
		Au[i] = 0;
		for (int j = 0; j < size; j++) {
			Au[i] += AEx[i][j] * vEx[j];
		}
	}
	double uAu = 0;
	for (int i = 0; i < size; i++) {
		uAu += vEx[i] * Au[i];
	}
	delete[] Au;
	return uAu;
}