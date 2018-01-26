#include "stdafx.h"
#include "FullLimitDirectivityOptimisationAlgoritm.h"

using namespace std;

FullLimitDirectivityOptimisationAlgoritm::FullLimitDirectivityOptimisationAlgoritm() {
	delete[] vEx;
}


FullLimitDirectivityOptimisationAlgoritm::~FullLimitDirectivityOptimisationAlgoritm()
{
}

void FullLimitDirectivityOptimisationAlgoritm::solveDirectivityOptimisationTask(OptimisationEnvirounment *envirounment) {
	/*NecIn *in = envirounment->getIn();
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
	//double d = 4 * PI*uAu / (uBu * dTheta * dTheta);

	//this->setD(d);
	this->set_uAu(uAu);
	this->setV(size, vEx);

	for (int i = 0; i < size; i++) {
		delete[] B[i];
		delete[] BInverse[i];
		delete[] AEx[i];
	}
	delete[] B;
	delete[] BInverse;
	delete[] AEx;*/
}


