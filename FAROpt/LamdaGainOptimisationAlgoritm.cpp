#include "stdafx.h"
#include "LamdaGainOptimisationAlgoritm.h"

LamdaGainOptimisationAlgoritm::LamdaGainOptimisationAlgoritm(OptimisationEnvirounment *envirounment) {
	this->solveOneLimitOptimisationTask(envirounment);
}

LamdaGainOptimisationAlgoritm::~LamdaGainOptimisationAlgoritm()
{
}

void LamdaGainOptimisationAlgoritm::solveOptimisationTask(OptimisationEnvirounment *envirounment) {
	this->solveLamdaOptimisationTask(envirounment, this->vEx, this->B, this->size);
}
