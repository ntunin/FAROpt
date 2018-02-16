#include "stdafx.h"
#include "FullLimitMultyThreadPowerOptimisationGradientSAScreen.h"



FullLimitMultyThreadPowerOptimisationGradientSAScreen::FullLimitMultyThreadPowerOptimisationGradientSAScreen(){
	this->apply();
}


void FullLimitMultyThreadPowerOptimisationGradientSAScreen::printHead() {
	print("----  Simulated annealing based on Hooke - Jeeves multy-thread optimisation of input power ----\n");
	print("----                                      Omsk, 2018                                ----\n");
	print("\n");
}

FAROptimisationAlgoritm *FullLimitMultyThreadPowerOptimisationGradientSAScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	int N = envirounment->getSourceCount();
	std::vector<double> *P = new std::vector<double>;
	Shared::bundle().log()->print("\nPlease enter input power limitations\n");
	for (int i = 0; i < N; i++) {
		P->push_back(Shared::bundle().scanner()->readDouble(std::to_string(i).append(": >")));
	}
	double T = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"temperature\" of the system: >");
	double speed = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"cool down speed\" of the system: >");
	double radius = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"random offset radius\": >");
	double mulctMultiplier = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" multiplier: >");
	double mulctDegree = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" degree: >");
	int threadsCount = Shared::bundle().scanner()->readInt("\nPlease, enter count of parallel solution threads: >");
	double randomStartRadius = Shared::bundle().scanner()->readDouble("\nPlease, enter of radius for random start points: >");
	return new FullLimitMultyThreadPowerOptimisationGradientSAAlgoritm(envirounment, P, T, speed, radius, mulctMultiplier, mulctDegree, threadsCount, randomStartRadius);
}


FullLimitMultyThreadPowerOptimisationGradientSAScreen::~FullLimitMultyThreadPowerOptimisationGradientSAScreen()
{
}