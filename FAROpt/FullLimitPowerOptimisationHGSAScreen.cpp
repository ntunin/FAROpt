#include "stdafx.h"
#include "FullLimitPowerOptimisationHGSAScreen.h"


FullLimitPowerOptimisationHGSAScreen::FullLimitPowerOptimisationHGSAScreen() {
	this->apply();
}


void FullLimitPowerOptimisationHGSAScreen::printHead() {
	print("----  Simulated annealing based on Hooke - Jeeves optimisation of input power ----\n");
	print("----                                  Omsk, 2018                              ----\n");
	print("\n");
}

FAROptimisationAlgoritm *FullLimitPowerOptimisationHGSAScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	int N = envirounment->getSourceCount();
	std::vector<double> *P = new std::vector<double>;
	Shared::bundle().log()->print("\nPlease enter input power limitations\n");
	for (int i = 0; i < N; i++) {
		P->push_back( Shared::bundle().scanner()->readDouble(std::to_string(i).append(": >")) );
	}
	double T = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"temperature\" of the system: >");
	double speed = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"cool down speed\" of the system: >");
	double radius = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"random offset radius\": >");
	double mulctMultiplier = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" multiplier: >");
	double mulctDegree = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" degree: >");
	return new FullLimitPowerOptimisationHGSAAlgoritm(envirounment, P, T, speed, radius, mulctMultiplier, mulctDegree);
}

FullLimitPowerOptimisationHGSAScreen::~FullLimitPowerOptimisationHGSAScreen()
{
}
