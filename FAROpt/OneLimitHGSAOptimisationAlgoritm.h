#pragma once
#include "OptimisationEnvirounment.h"
#include "HGSAAlgoritm.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

class OneLimitHGSAOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public HGSAAlgoritm {
public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	OneLimitHGSAOptimisationAlgoritm(OptimisationEnvirounment *envirounment, double T, double coolDownSpeed, double radius);
	~OneLimitHGSAOptimisationAlgoritm();
};

