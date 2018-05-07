#pragma once
#include "FAROptimisationAlgoritm.h"
#include "OptimisationEnvirounment.h"
#include "Task.h"
#include "FullLimitPowerOptimisationHGAlgoritm.h"
class FullLimitMultithreadPowerOptimisationHGAlgoritm :
	public FAROptimisationAlgoritm {
private:
	void printResult();
	class SolutionTask : public Task {
	private:
		OptimisationEnvirounment * envirounment;
		double mulctMultiplier;
		double mulctDegree;
		std::vector<double> *P;
		double randomStartRadius;
		FullLimitPowerOptimisationHGAlgoritm *algorithm;
		void printResult();

	public:
		SolutionTask(OptimisationEnvirounment *envirounment, std::vector<double> *P, double mulctMultiplier, double mulctDegree, double randomStartRadius);
		~SolutionTask();
		FullLimitPowerOptimisationHGAlgoritm *getAlgorithm();
		void execute();
	};


	std::vector<SolutionTask *> tasks;
	int threadsCount;


public:
	FullLimitMultithreadPowerOptimisationHGAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P, double mulctMultiplier, double mulctDegree, int threadsCount, double randomStartRadius);
	~FullLimitMultithreadPowerOptimisationHGAlgoritm();
};

