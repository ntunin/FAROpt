#pragma once
#include "FAROptimisationAlgoritm.h"
#include "OptimisationEnvirounment.h"
#include "Task.h"
#include "FullLimitPowerOptimisationGradientSAAlgoritm.h"
class FullLimitMultyThreadPowerOptimisationGradientSAAlgoritm :
	public FAROptimisationAlgoritm
{
private:
	class SolutionTask : public Task {
	private:
		OptimisationEnvirounment *envirounment;
		double mulctMultiplier;
		double mulctDegree;
		int threadsCount;
		std::vector<double> *P;
		double T;
		double coolDownSpeed;
		double radius;
		double randomStartRadius;
		FullLimitPowerOptimisationGradientSAAlgoritm *algorithm;

	public:
		SolutionTask(OptimisationEnvirounment *envirounment, std::vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, double randomStartRadius);
		~SolutionTask();
		FullLimitPowerOptimisationGradientSAAlgoritm *getAlgorithm();
		void execute();
	};


	std::vector<SolutionTask *> tasks;
public:
	FullLimitMultyThreadPowerOptimisationGradientSAAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, int threadsCount, double randomStartRadius);
	~FullLimitMultyThreadPowerOptimisationGradientSAAlgoritm();
};

