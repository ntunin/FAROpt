#include "stdafx.h"
#include "FullLimitDirectivityPseudoOptimisationAlgoritm.h"


FullLimitDirectivityPseudoOptimisationAlgoritm::FullLimitDirectivityPseudoOptimisationAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P) {
	this->P = P;
	this->solveFullLimitOptimisationTask(envirounment);
}

void FullLimitDirectivityPseudoOptimisationAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
	std::vector<double **> *B = calculateB(envirounment);
	int N = envirounment->getSourceCount();
	double **summaryB = new double*[this->size];
	for (int i = 0; i < this->size; i++) {
		summaryB[i] = new double[this->size];
		for (int j = 0; j < this->size; j++) {
			summaryB[i][j] = 0;
			for (int k = 0; k < N; k++) {
				summaryB[i][j] += (*B)[k][i][j];
			}
		}
	}
	this->solveLamdaOptimisationTask(envirounment, this->vEx, summaryB, this->size);
	for (int i = 0; i < this->size; i++) {
		delete[] summaryB[i];
	}
	delete[] summaryB;
}


FullLimitDirectivityPseudoOptimisationAlgoritm::~FullLimitDirectivityPseudoOptimisationAlgoritm()
{
}
