#pragma once
#include "OptimisationEnvirounment.h"
class LamdaOptimisationAlgoritm
{
protected:
	void solveLamdaOptimisationTask(OptimisationEnvirounment *envirounment, double *vEx, double **B, int size);
public:
	LamdaOptimisationAlgoritm();
	~LamdaOptimisationAlgoritm();
};

