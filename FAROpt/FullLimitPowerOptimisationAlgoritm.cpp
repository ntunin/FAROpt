#include "stdafx.h"
#include "FullLimitPowerOptimisationAlgoritm.h"

using namespace std;

FullLimitPowerOptimisationAlgoritm::FullLimitPowerOptimisationAlgoritm()
{
}


FullLimitPowerOptimisationAlgoritm::~FullLimitPowerOptimisationAlgoritm()
{
}

double **buildProjector(int k, int N) {
	double **P = new double*[N];
	for (int i = 0; i < N; i++) {
		P[i] = new double[N];
		for (int j = 0; j < N; j++) {
			P[i][j] = (i == k && j == k) ? 1 : 0;
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
		double **Pk = buildProjector(k, N);
		ComplexMatrix Bk(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Complex _y = (*_Y)[i][j];
				double p = Pk[i][j];
				Complex y = (*Y)[i][j];
				Complex yp = _y * p + y * p;
				Complex b = yp * (1.0 / (4 * (*this->P)[k]));
				Bk[i][j].copy(b);
			}
		}
		B->push_back( Bk.doubleExtend() );
		for (int i = 0; i < N; i++) {
			delete[] Pk[i];
		}
		delete[] Pk;
	}
	delete Y;
	return B;
}