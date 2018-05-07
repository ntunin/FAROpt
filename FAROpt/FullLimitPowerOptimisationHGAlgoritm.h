#pragma once
#include "FullLimitPowerOptimisationAlgoritm.h"
#include "HGAlgoritm.h"
#include "OptimisationEnvirounment.h"
class FullLimitPowerOptimisationHGAlgoritm :
	public FullLimitPowerOptimisationAlgoritm,
	public HGAlgoritm {
private:
	double mulctMultiplier;
	double mulctDegree;
	double randomStartRadius;
	double *customStart;
	bool inside;


public:
	FullLimitPowerOptimisationHGAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P,double mulctMultiplier, double mulctDegree);
	FullLimitPowerOptimisationHGAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double mulctMultiplier, double mulctDegree, double randomStartRadius);
	~FullLimitPowerOptimisationHGAlgoritm();
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
};
