#pragma once
#include "OneLimitOptimisationEnvirounment.h"
#include "SimulatedAnealingAlgoritm.h"
#include "OneLimitDirectivityOptimisationAlgoritm.h"

class OneLimitSimulatedAnealingOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public SimulatedAnealingAlgoritm {
public:
	void solveOptimisationTask(OneLimitOptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	OneLimitSimulatedAnealingOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment, double T, double coolDownSpeed, double radius);
	~OneLimitSimulatedAnealingOptimisationAlgoritm();
};

