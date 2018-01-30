#include "stdafx.h"
#include "FullLimitPowerOptimisationGradientSAScreen.h"


FullLimitPowerOptimisationGradientSAScreen::FullLimitPowerOptimisationGradientSAScreen() {
	this->apply();
}


void FullLimitPowerOptimisationGradientSAScreen::printHead() {
	print("---- Simulated annealing based on Gradient optimisation of input power ----\n");
	print("----                              Omsk, 2018                           ----\n");
	print("\n");
}

FAROptimisationAlgoritm *FullLimitPowerOptimisationGradientSAScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
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
	return new FullLimitPowerOptimisationGradientSAAlgoritm(envirounment, P, T, speed, radius, mulctMultiplier, mulctDegree);
}

FullLimitPowerOptimisationGradientSAScreen::~FullLimitPowerOptimisationGradientSAScreen()
{
}
