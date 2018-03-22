#include "stdafx.h"
#include "FullLimitMultithreadPowerOptimisationHGAlgoritm.h"


using namespace std;

FullLimitMultithreadPowerOptimisationHGAlgoritm::FullLimitMultithreadPowerOptimisationHGAlgoritm(OptimisationEnvirounment *envirounment, vector<double> *P, double mulctMultiplier, double mulctDegree, int threadsCount, double randomStartRadius) {
	for (int i = 0; i < threadsCount; i++) {
		SolutionTask *task = new SolutionTask(envirounment, P, mulctMultiplier, mulctDegree, randomStartRadius);
		Shared::bundle().taskManager()->execute(task);
		tasks.push_back(task);
	}
	for (int i = 0; i < threadsCount; i++) {
		SolutionTask *task = tasks[i];
		Shared::bundle().taskManager()->wait(task);
	}
	double target = -DBL_MAX;
	FullLimitPowerOptimisationHGAlgoritm *algorithm = NULL;
	for (int i = 0; i < threadsCount; i++) {
		SolutionTask *task = tasks[i];
		FullLimitPowerOptimisationHGAlgoritm *newAlgorithm = task->getAlgorithm();
		double *v = newAlgorithm->getV()->extendDouble();
		double newTarget = newAlgorithm->targetFunction(v);
		if (newTarget > target) {
			target = newTarget;
			algorithm = newAlgorithm;
		}
		delete[] v;
	}
	int sourceCount = envirounment->getSourceCount();
	if (algorithm) {
		double *v = algorithm->getV()->extendDouble();
		this->setV(2 * sourceCount, v);
		this->set_uAu(algorithm->get_uAu());
		this->set_uBu(algorithm->get_uBu());
		delete[] v;
	}
}

FullLimitMultithreadPowerOptimisationHGAlgoritm::SolutionTask::SolutionTask(OptimisationEnvirounment *envirounment, vector<double> *P, double mulctMultiplier, double mulctDegree, double randomStartRadius) {
	this->P = P;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->envirounment = envirounment;
	this->randomStartRadius = randomStartRadius;
}

void FullLimitMultithreadPowerOptimisationHGAlgoritm::SolutionTask::execute() {
	this->algorithm = new FullLimitPowerOptimisationHGAlgoritm(envirounment, P, mulctMultiplier, mulctDegree, randomStartRadius);
}

FullLimitPowerOptimisationHGAlgoritm *FullLimitMultithreadPowerOptimisationHGAlgoritm::SolutionTask::getAlgorithm() {
	return this->algorithm;
}

FullLimitMultithreadPowerOptimisationHGAlgoritm::SolutionTask::~SolutionTask() {
	delete algorithm;
}

FullLimitMultithreadPowerOptimisationHGAlgoritm::~FullLimitMultithreadPowerOptimisationHGAlgoritm() {
	int threadsCount = tasks.size();
	for (int i = 0; i < threadsCount; i++) {
		SolutionTask *task = tasks[i];
		delete task;
	}
}

