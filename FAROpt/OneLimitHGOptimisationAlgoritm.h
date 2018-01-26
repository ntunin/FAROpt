#pragma once
#include "OptimisationEnvirounment.h"
#include "HGAlgoritm.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

class OneLimitHGOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public HGAlgoritm {
public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	OneLimitHGOptimisationAlgoritm(OptimisationEnvirounment *envirounment);
	~OneLimitHGOptimisationAlgoritm();
};

