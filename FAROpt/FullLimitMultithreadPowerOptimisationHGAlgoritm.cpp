#include "stdafx.h"
#include "FullLimitMultithreadPowerOptimisationHGAlgoritm.h"


using namespace std;
mutex logFileMtx;

FullLimitMultithreadPowerOptimisationHGAlgoritm::FullLimitMultithreadPowerOptimisationHGAlgoritm(OptimisationEnvirounment *envirounment, vector<double> *P, double mulctMultiplier, double mulctDegree, int threadsCount, double randomStartRadius) {
	this->threadsCount = threadsCount;
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
	printResult();
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
	this->printResult();
}

void FullLimitMultithreadPowerOptimisationHGAlgoritm::printResult() {
	FileLog log("log.txt");
	log.print("\n");
	int size = 2 * tasks[0]->getAlgorithm()->getV()->length();
	double **normals = new double*[threadsCount];
	for (int i = 0; i < threadsCount; i++) {
		FAROptimisationAlgoritm *algoritm = tasks[i]->getAlgorithm();
		ComplexVector *v = algoritm->getV();
		normals[i] = new double[size];
		Utils::normalize(v, normals[i]);
		log.print(normals[i], size);
		log.print("\n");
	}
	log.print("\n");


	for (double epsilon = 1; epsilon > 1e-8; epsilon /= 10) {
		vector<double *> differentSolutions;
		for (int i = 0; i < threadsCount; i++) {
			double *norma = normals[i];
			boolean isUnique = true;
			for (int j = 0; j < differentSolutions.size(); j++) {
				double *templateNorma = differentSolutions[j];
				if (Utils::equals(norma, templateNorma, size, epsilon)) {
					isUnique = false;
					break;
				}
			}
			if (isUnique) {
				differentSolutions.push_back(norma);
			}
		}
		log.print(differentSolutions.size());
		log.print("\t");

	}
	log.print("\n");

}


void FullLimitMultithreadPowerOptimisationHGAlgoritm::SolutionTask::printResult() {
	unique_lock<mutex> lck(logFileMtx, defer_lock);
	lck.lock();
	FileLog log("log.txt");
	//ConsoleLog log = *(ConsoleLog *)Shared::bundle().log();
	log.print(this->algorithm->get_uAu());
	log.print("\t");
	vector<double> *uBu = this->algorithm->get_uBu();
	int size = uBu->size();
	for (int i = 0; i < size; i++) {
		log.print((*uBu)[i]);
		log.print("\t");
	}
	log.print(*this->algorithm->getV());
	for (int i = 0; i < size; i++) {
		log.print(this->algorithm->start[i]);
		log.print("\t");
		log.print(this->algorithm->start[i + size]);
		log.print("\t");
	}
	double *I = new double[2 * size];
	Utils::mul(2 * size, envirounment->getY()->doubleExtend(), this->algorithm->getV()->extendDouble(), I);
	log.print("\n");
	lck.unlock();

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

