#pragma once
#include "OptimisationEnvirounment.h"
#include "SimulatedAnealingAlgoritm.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

class OneLimitSimulatedAnealingOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public SimulatedAnealingAlgoritm {
public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	OneLimitSimulatedAnealingOptimisationAlgoritm(OptimisationEnvirounment *envirounment, double T, double coolDownSpeed, double radius);
	~OneLimitSimulatedAnealingOptimisationAlgoritm();
};

