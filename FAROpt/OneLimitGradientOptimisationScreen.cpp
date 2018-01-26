#include "stdafx.h"
#include "OneLimitGradientOptimisationScreen.h"


OneLimitGradientOptimisationScreen::OneLimitGradientOptimisationScreen() {
	this->apply();
}

void OneLimitGradientOptimisationScreen::printHead() {
	print("---- 1-Limited simulated anealing based on gradient optimisation algoritm ----\n");
	print("----                Omsk, 2018                ----\n");
	print("\n");
}

FAROptimisationAlgoritm *OneLimitGradientOptimisationScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	double mulctMultiplier = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" multiplier: >");
	double mulctDegree = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" degree: >");
	return new OneLimitGradientOptimisationAlgoritm(envirounment, mulctMultiplier, mulctDegree);
}

OneLimitGradientOptimisationScreen::~OneLimitGradientOptimisationScreen() {
}
