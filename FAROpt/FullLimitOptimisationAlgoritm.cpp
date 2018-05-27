#include "stdafx.h"
#include "FullLimitOptimisationAlgoritm.h"
#include "FileLog.h"

using namespace std;

FullLimitOptimisationAlgoritm::FullLimitOptimisationAlgoritm()
{
}

FullLimitOptimisationAlgoritm::~FullLimitOptimisationAlgoritm() {
	for (int i = 0; i < size; i++) {
		delete[] AEx[i];
	}
	delete[] AEx;
	int sourceCount = size / 2;
	for (int k = 0; k < sourceCount; k++) {
		double **Bk = (*B)[k];
		for (int i = 0; i < size; i++) {
			delete[] Bk[i];
		}
		delete[] Bk;
	}
	delete B;
	delete[] Au;
	delete[] Bu;
}


void FullLimitOptimisationAlgoritm::solveFullLimitOptimisationTask(OptimisationEnvirounment *envirounment) {
	NecIn *in = envirounment->getIn();
	vector<EX *> *sources = in->getEX();
	RP *rp = in->getRP();
	double dTheta = rp->getThetaInc() * PI / 180;
	int sourceCount = envirounment->getSourceCount();
	this->size = 2 * sourceCount;
	this->B = calculateB(envirounment);

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
	Au = new double[size];
	Bu = new double[size];
	lastCheckedSolution = new double[size];
	uBus = new vector<double>;

	Log *log = new FileLog("mtrices.txt");
	log->print(this->AEx, this->size);
	log->print("\n");
	for (int i = 0; i < sourceCount; i++) {
		double **B = (*this->B)[i];
		log->print("\n");
		log->print(B, this->size);
		log->print("\n");
	}
	log->print("\n");
	delete log;

	solveOptimisationTask(envirounment);




	double uAu = calculate_uAu(vEx);
	vector<double> *uBu = calculate_uBu(vEx);
	this->set_uAu(uAu);
	this->set_uBu(uBu);
	this->setV(size, vEx);
}

double FullLimitOptimisationAlgoritm::calculate_uAu(double *vEx) {
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
	return uAu;
}

vector<double> * FullLimitOptimisationAlgoritm::calculate_uBu(double *vEx) {
	bool sameSolution = true;
	for (int i = 0; i < size; i++) {
		if (vEx[i] != lastCheckedSolution[i]) {
			sameSolution = false;
			break;
		}
	}
	if (sameSolution) {
		return uBus;
	}
	for (int i = 0; i < size; i++) {
		lastCheckedSolution[i] = vEx[i];
	}
	int N = (*this->B).size();
	uBus->clear();
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < size; i++) {
			Bu[i] = 0;
			for (int j = 0; j < size; j++) {
				double b = (*this->B)[k][i][j];
				Bu[i] += (*this->B)[k][i][j] * vEx[j];
			}
		}
		double uBu = 0;
		for (int i = 0; i < size; i++) {
			uBu += vEx[i] * Bu[i];
		}
		uBus->push_back(uBu);
	}
	return uBus;
}