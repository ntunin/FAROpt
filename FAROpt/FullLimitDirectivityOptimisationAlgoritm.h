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
	void solveDirectivityOptimisationTask(OneLimitOptimisationEnvirounment *envirounment);
	virtual void solveOptimisationTask(OneLimitOptimisationEnvirounment *envirounment) = 0;
public:
	FullLimitDirectivityOptimisationAlgoritm();
	~FullLimitDirectivityOptimisationAlgoritm();
};

