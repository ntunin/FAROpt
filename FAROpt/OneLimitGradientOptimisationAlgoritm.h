#pragma once
#include "OneLimitOptimisationEnvirounment.h"
#include "GradientAlgoritm.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

class OneLimitGradientOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public GradientAlgoritm {
public:
	void solveOptimisationTask(OneLimitOptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	OneLimitGradientOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment);
	~OneLimitGradientOptimisationAlgoritm();
};

