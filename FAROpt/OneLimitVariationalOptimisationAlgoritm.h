#pragma once
#include "OneLimitDirectivityOptimisationAlgoritm.h"
#include "OptimisationAlgoritm.h"
#include "OneLimitOptimisationEnvirounment.h"

class OneLimitVariationalOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public OptimisationAlgoritm {
public:
	void solveOptimisationTask(OneLimitOptimisationEnvirounment *envirounment);
	virtual void solveVariationalOptimisationTask() = 0;
	OneLimitVariationalOptimisationAlgoritm();
	double targetFunction(double *x);
	~OneLimitVariationalOptimisationAlgoritm();
};

