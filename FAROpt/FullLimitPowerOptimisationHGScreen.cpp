#include "stdafx.h"
#include "FullLimitPowerOptimisationHGScreen.h"


FullLimitPowerOptimisationHGScreen::FullLimitPowerOptimisationHGScreen() {
	this->apply();
}


void FullLimitPowerOptimisationHGScreen::printHead() {
	print("----  Hooke - Jeeves optimisation of input power ----\n");
	print("----                 Omsk, 2018                  ----\n");
	print("\n");
}

FAROptimisationAlgoritm *FullLimitPowerOptimisationHGScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	int N = envirounment->getSourceCount();
	std::vector<double> *P = new std::vector<double>;
	Shared::bundle().log()->print("\nPlease enter input power limitations\n");
	for (int i = 0; i < N; i++) {
		P->push_back(Shared::bundle().scanner()->readDouble(std::to_string(i).append(": >")));
	}
	double mulctMultiplier = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" multiplier: >");
	double mulctDegree = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" degree: >");

	std::uint64_t start = WindowsUtils::time();
	FullLimitPowerOptimisationHGAlgoritm *a = new FullLimitPowerOptimisationHGAlgoritm(envirounment, P, mulctMultiplier, mulctDegree);
	std::uint64_t end = WindowsUtils::time();
	workingTime = end - start;
	return a;
}


FullLimitPowerOptimisationHGScreen::~FullLimitPowerOptimisationHGScreen()
{
}
