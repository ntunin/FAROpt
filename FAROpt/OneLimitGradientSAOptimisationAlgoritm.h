#pragma once
#include "OneLimitDirectivityOptimisationAlgoritm.h"
#include "GradientSAAlgoritm.h"

class OneLimitGradientSAOptimisationAlgoritm :
	public OneLimitDirectivityOptimisationAlgoritm,
	public GradientSAAlgoritm
{
private:
	double mulctMultiplier;
	double mulctDegree;
public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	void getGradient(double *x, double *dF, int size);
	OneLimitGradientSAOptimisationAlgoritm(OptimisationEnvirounment *envirounment, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree);
	~OneLimitGradientSAOptimisationAlgoritm();
};

