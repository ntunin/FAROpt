#pragma once
#include "FullLimitOptimisationAlgoritm.h"
class FullLimitDirectivityOptimisationAlgoritm :
	public FullLimitOptimisationAlgoritm
{
protected:
	int size;
	double *vEx;
	double **B;
	double **BInverse;
	double **AEx;
	double calculate_uAu(double *vEx);
	void solveDirectivityOptimisationTask(OptimisationEnvirounment *envirounment);
	virtual void solveOptimisationTask(OptimisationEnvirounment *envirounment) = 0;
public:
	FullLimitDirectivityOptimisationAlgoritm();
	~FullLimitDirectivityOptimisationAlgoritm();
};

