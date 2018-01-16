#pragma once
#include "OptimisationEnvirounment.h"
#include "GradientAlgoritm.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

class OneLimitGradientOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public GradientAlgoritm {
public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	OneLimitGradientOptimisationAlgoritm(OptimisationEnvirounment *envirounment);
	~OneLimitGradientOptimisationAlgoritm();
};

