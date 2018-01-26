#pragma once
#include "OneLimitDirectivityOptimisationAlgoritm.h"
#include "GradientAlgoritm.h"
#include "OptimisationEnvirounment.h"

class OneLimitGradientOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public GradientAlgoritm {
private:
	double mulctMultiplier;
	double mulctDegree;
public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	void getGradient(double *x, double *dF, int size);
	OneLimitGradientOptimisationAlgoritm(OptimisationEnvirounment *envirounment, double mulctMultiplier, double mulctDegree);
	~OneLimitGradientOptimisationAlgoritm();
};

