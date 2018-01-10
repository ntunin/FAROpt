#pragma once
#include "OneLimitOptimisationAlgoritm.h"
#include "OneLimitOptimisationEnvirounment.h"
#include "GradientAlgoritm.h"

class OneLimitGradientOptimisationAlgoritm :
	public OneLimitOptimisationAlgoritm,
	public GradientAlgoritm
{
private:
	int size;
	double *vEx;
	double **B;
	double **BInverse; 
	double **AEx;
	double calculate_uAu(double *vEx);
	double calculate_uBu(double *vEx);
public:
	OneLimitGradientOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment);
	~OneLimitGradientOptimisationAlgoritm();
	double targetFunction(double *x);
};

