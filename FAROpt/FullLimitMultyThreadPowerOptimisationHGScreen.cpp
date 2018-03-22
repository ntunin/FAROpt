#include "stdafx.h"
#include "FullLimitMultyThreadPowerOptimisationHGScreen.h"


FullLimitMultyThreadPowerOptimisationHGScreen::FullLimitMultyThreadPowerOptimisationHGScreen() {
	this->apply();
}


void FullLimitMultyThreadPowerOptimisationHGScreen::printHead() {
	print("----  Hooke - Jeeves multy-thread optimisation of input power ----\n");
	print("----                    Omsk, 2018                            ----\n");
	print("\n");
}

FAROptimisationAlgoritm *FullLimitMultyThreadPowerOptimisationHGScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	int N = envirounment->getSourceCount();
	std::vector<double> *P = new std::vector<double>;
	Shared::bundle().log()->print("\nPlease enter input power limitations\n");
	for (int i = 0; i < N; i++) {
		P->push_back(Shared::bundle().scanner()->readDouble(std::to_string(i).append(": >")));
	}
	double mulctMultiplier = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" multiplier: >");
	double mulctDegree = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" degree: >");
	int threadsCount = Shared::bundle().scanner()->readInt("\nPlease, enter count of parallel solution threads: >");
	double randomStartRadius = Shared::bundle().scanner()->readDouble("\nPlease, enter of radius for random start points: >");
	return new FullLimitMultithreadPowerOptimisationHGAlgoritm(envirounment, P, mulctMultiplier, mulctDegree, threadsCount, randomStartRadius);
}


FullLimitMultyThreadPowerOptimisationHGScreen::~FullLimitMultyThreadPowerOptimisationHGScreen()
{
}
