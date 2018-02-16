#include "stdafx.h"
#include "FullLimitDirectivityPseudoOptimisationScreen.h"
#include "FullLimitDirectivityPseudoOptimisationAlgoritm.h"

FullLimitDirectivityPseudoOptimisationScreen::FullLimitDirectivityPseudoOptimisationScreen() {
	this->apply();
}


void FullLimitDirectivityPseudoOptimisationScreen::printHead() {
	print("---- Pseudo optimisation based on lamda-algorithm ----\n");
	print("----               Omsk, 2018                     ----\n");
	print("\n");
}

FAROptimisationAlgoritm *FullLimitDirectivityPseudoOptimisationScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	std::vector<double> *P = new std::vector<double>;
	Shared::bundle().log()->print("\nPlease enter input power limitations\n");
	int N = envirounment->getSourceCount();
	for (int i = 0; i < N; i++) {
		P->push_back(Shared::bundle().scanner()->readDouble(std::to_string(i).append(": >")));
	}
	return new FullLimitDirectivityPseudoOptimisationAlgoritm(envirounment, P);
}

FullLimitDirectivityPseudoOptimisationScreen::~FullLimitDirectivityPseudoOptimisationScreen()
{
}
