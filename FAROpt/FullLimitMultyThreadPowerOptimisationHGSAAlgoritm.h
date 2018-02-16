#pragma once
#include "FAROptimisationAlgoritm.h"
#include "OptimisationEnvirounment.h"
#include "Task.h"
#include "FullLimitPowerOptimisationHGSAAlgoritm.h"

class FullLimitMultyThreadPowerOptimisationHGSAAlgoritm :
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
		FullLimitPowerOptimisationHGSAAlgoritm *algorithm;

	public:
		SolutionTask(OptimisationEnvirounment *envirounment, std::vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, double randomStartRadius);
		~SolutionTask();
		FullLimitPowerOptimisationHGSAAlgoritm *getAlgorithm();
		void execute();
	};


	std::vector<SolutionTask *> tasks;


public:
	FullLimitMultyThreadPowerOptimisationHGSAAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, int threadsCount, double randomStartRadius);
	~FullLimitMultyThreadPowerOptimisationHGSAAlgoritm();
};

