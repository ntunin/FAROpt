#include "stdafx.h"
#include "OneLimitGainOptimisationAlgoritm.h"


OneLimitGainOptimisationAlgoritm::OneLimitGainOptimisationAlgoritm()
{
}

OneLimitGainOptimisationAlgoritm::~OneLimitGainOptimisationAlgoritm()
{
}

double **OneLimitGainOptimisationAlgoritm::calculateB(OptimisationEnvirounment *envirounment) {
	int size = envirounment->getSourceCount();
	int dSize = 2 * size;
	ComplexMatrix *Y = envirounment->getY();
	double **B = new double *[dSize];
	for (int i = 0; i < size; i++) {
		B[i] = new double[dSize];
		B[i + size] = new double[dSize];
		for (int j = 0; j < size; j++) {
			double y = (*Y)[i][j].Re();
			B[i][j] = y;
			B[i + size][j + size] = y;
			B[i][j + size] = 0;
			B[i + size][j] = 0;
		}
	}
	return B;
}
