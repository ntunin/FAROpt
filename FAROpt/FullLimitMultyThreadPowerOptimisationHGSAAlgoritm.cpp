#include "stdafx.h"
#include "FullLimitMultyThreadPowerOptimisationHGSAAlgoritm.h"

using namespace std;

FullLimitMultyThreadPowerOptimisationHGSAAlgoritm::FullLimitMultyThreadPowerOptimisationHGSAAlgoritm(OptimisationEnvirounment *envirounment, vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, int threadsCount, double randomStartRadius) {
	for (int i = 0; i < threadsCount; i++) {
		SolutionTask *task = new SolutionTask(envirounment, P, T, coolDownSpeed, radius, mulctMultiplier, mulctDegree, randomStartRadius);
		Shared::bundle().taskManager()->execute(task);
		tasks.push_back(task);
	}
	for (int i = 0; i < threadsCount; i++) {
		SolutionTask *task = tasks[i];
		Shared::bundle().taskManager()->wait(task);
	}
	double target = -DBL_MAX;
	FullLimitPowerOptimisationHGSAAlgoritm *algorithm = NULL;
	for (int i = 0; i < threadsCount; i++) {
		SolutionTask *task = tasks[i];
		FullLimitPowerOptimisationHGSAAlgoritm *newAlgorithm = task->getAlgorithm();
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
		this->setV(2*sourceCount, v);
		this->set_uAu(algorithm->get_uAu());
		this->set_uBu(algorithm->get_uBu());
		delete[] v;
	}
}

FullLimitMultyThreadPowerOptimisationHGSAAlgoritm::SolutionTask::SolutionTask(OptimisationEnvirounment *envirounment, vector<double> *P, double T, double coolDownSpeed, double radius, double mulctMultiplier, double mulctDegree, double randomStartRadius) {
	this->P = P;
	this->T = T;
	this->coolDownSpeed = coolDownSpeed;
	this->radius = radius;
	this->mulctMultiplier = mulctMultiplier;
	this->mulctDegree = mulctDegree;
	this->envirounment = envirounment;
	this->randomStartRadius = randomStartRadius;
}

void FullLimitMultyThreadPowerOptimisationHGSAAlgoritm::SolutionTask::execute() {
	this->algorithm = new FullLimitPowerOptimisationHGSAAlgoritm(envirounment, P, T, coolDownSpeed, radius, mulctMultiplier, mulctDegree, randomStartRadius);
}

FullLimitPowerOptimisationHGSAAlgoritm *FullLimitMultyThreadPowerOptimisationHGSAAlgoritm::SolutionTask::getAlgorithm() {
	return this->algorithm;
}

FullLimitMultyThreadPowerOptimisationHGSAAlgoritm::SolutionTask::~SolutionTask() {
	delete algorithm;
}

FullLimitMultyThreadPowerOptimisationHGSAAlgoritm::~FullLimitMultyThreadPowerOptimisationHGSAAlgoritm() {
	int threadsCount = tasks.size();
	for (int i = 0; i < threadsCount; i++) {
		SolutionTask *task = tasks[i];
		delete task;
	}
}
