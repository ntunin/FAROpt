#pragma once
#include "OneLimitOptimisationAlgoritm.h"

class OneLimitDirectivityOptimisationAlgoritm :
	public OneLimitOptimisationAlgoritm
{
protected:
	int size;
	double *vEx;
	double **B;
	double **BInverse;
	double **AEx;
	double calculate_uAu(double *vEx);
	double calculate_uBu(double *vEx);
	void solveDirectivityOptimisationTask(OneLimitOptimisationEnvirounment *envirounment);
	virtual void solveOptimisationTask(OneLimitOptimisationEnvirounment *envirounment) = 0;
public:
	OneLimitDirectivityOptimisationAlgoritm();
	~OneLimitDirectivityOptimisationAlgoritm();

};

