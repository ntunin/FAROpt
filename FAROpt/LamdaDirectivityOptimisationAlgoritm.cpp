#include "stdafx.h"
#include "LamdaDirectivityOptimisationAlgoritm.h"

LamdaDirectivityOptimisationAlgoritm::LamdaDirectivityOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment) {
	solveDirectivityOptimisationTask(envirounment);
}

void LamdaDirectivityOptimisationAlgoritm::solveOptimisationTask(OneLimitOptimisationEnvirounment *envirounment) {
	double *gEx = envirounment->getGEx();

	for (int i = 0; i < size; i++) {
		vEx[i] = 0;
		for (int j = 0; j < size; j++) {
			vEx[i] += BInverse[i][j] * gEx[j];
		}
	}
}


LamdaDirectivityOptimisationAlgoritm::~LamdaDirectivityOptimisationAlgoritm()
{
}
