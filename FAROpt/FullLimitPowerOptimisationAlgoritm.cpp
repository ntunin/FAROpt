#include "stdafx.h"
#include "FullLimitPowerOptimisationAlgoritm.h"

using namespace std;

FullLimitPowerOptimisationAlgoritm::FullLimitPowerOptimisationAlgoritm()
{
}


FullLimitPowerOptimisationAlgoritm::~FullLimitPowerOptimisationAlgoritm()
{
}

ComplexMatrix *buildProjector(int k, int N) {
	ComplexMatrix *P = new ComplexMatrix(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			(*P)[i][j] = Complex((i == k && j == k) ? 1 : 0, 0);
		}
	}
	return P;
}

vector<double **> *FullLimitPowerOptimisationAlgoritm::calculateB(OptimisationEnvirounment *envirounment) {
	vector<double **> *B = new vector<double **>;
	int N = this->P->size();
	ComplexMatrix *Y = envirounment->getY();
	ComplexMatrix *_Y = Y->econj();
	for (int k = 0; k < N; k++) {
		int dSize = 2 * N;
		ComplexMatrix *Pk = buildProjector(k, N);
		double **Bk = ((*_Y)*(*Pk) + (*Pk)*(*Y)).doubleExtend();
		B->push_back( Bk );
		delete Pk;
	}
	return B;
}