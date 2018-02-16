#pragma once
#include "FullLimitPowerOptimisationAlgoritm.h"
#include "HGSAAlgoritm.h"
#include "OptimisationEnvirounment.h"

class FullLimitPowerOptimisationHGSAAlgoritm :
	public FullLimitPowerOptimisationAlgoritm,
	public HGSAAlgoritm {
private:
	double mulctMultiplier;
	double mulctDegree;
	double randomStartRadius;
public:
	FullLimitPowerOptimisationHGSAAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree);
	FullLimitPowerOptimisationHGSAAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, double randomStartRadius);
	~FullLimitPowerOptimisationHGSAAlgoritm();
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	double targetFunction(double *x);
};

