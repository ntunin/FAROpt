#pragma once
#include "FullLimitPowerOptimisationAlgoritm.h"
#include "GradientSAAlgoritm.h"
#include "OptimisationEnvirounment.h"

class FullLimitPowerOptimisationGradientSAAlgoritm :
	public FullLimitPowerOptimisationAlgoritm,
	public GradientSAAlgoritm {
private:
	double mulctMultiplier;
	double mulctDegree;
public:
	FullLimitPowerOptimisationGradientSAAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree);
	~FullLimitPowerOptimisationGradientSAAlgoritm();
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
	void getGradient(double *x, double *dF, int size);
};

