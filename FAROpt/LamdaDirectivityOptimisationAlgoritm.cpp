#include "stdafx.h"
#include "LamdaDirectivityOptimisationAlgoritm.h"

LamdaDirectivityOptimisationAlgoritm::LamdaDirectivityOptimisationAlgoritm(OptimisationEnvirounment *envirounment) {
	this->solveOneLimitOptimisationTask(envirounment);
}

void LamdaDirectivityOptimisationAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
	this->solveLamdaOptimisationTask(envirounment, this->vEx, this->B, this->size);
}


LamdaDirectivityOptimisationAlgoritm::~LamdaDirectivityOptimisationAlgoritm()
{
}
