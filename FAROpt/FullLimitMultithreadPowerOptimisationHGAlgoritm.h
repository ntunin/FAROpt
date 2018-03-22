#pragma once
#include "FAROptimisationAlgoritm.h"
#include "OptimisationEnvirounment.h"
#include "Task.h"
#include "FullLimitPowerOptimisationHGAlgoritm.h"
class FullLimitMultithreadPowerOptimisationHGAlgoritm :
	public FAROptimisationAlgoritm {
private:
	class SolutionTask : public Task {
	private:
		OptimisationEnvirounment * envirounment;
		double mulctMultiplier;
		double mulctDegree;
		int threadsCount;
		std::vector<double> *P;
		double randomStartRadius;
		FullLimitPowerOptimisationHGAlgoritm *algorithm;

	public:
		SolutionTask(OptimisationEnvirounment *envirounment, std::vector<double> *P, double mulctMultiplier, double mulctDegree, double randomStartRadius);
		~SolutionTask();
		FullLimitPowerOptimisationHGAlgoritm *getAlgorithm();
		void execute();
	};


	std::vector<SolutionTask *> tasks;


public:
	FullLimitMultithreadPowerOptimisationHGAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double mulctMultiplier, double mulctDegree, int threadsCount, double randomStartRadius);
	~FullLimitMultithreadPowerOptimisationHGAlgoritm();
};

