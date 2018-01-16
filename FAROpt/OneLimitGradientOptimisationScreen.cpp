#include "stdafx.h"
#include "OneLimitGradientOptimisationScreen.h"



OneLimitGradientOptimisationScreen::OneLimitGradientOptimisationScreen() {
	this->apply();
}

void OneLimitGradientOptimisationScreen::printHead() {
	print("---- 1-Limited gradient optimisation algoritm ----\n");
	print("----                Omsk, 2017                ----\n");
	print("\n");
}

FAROptimisationAlgoritm *OneLimitGradientOptimisationScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	return new OneLimitGradientOptimisationAlgoritm(envirounment);
}

OneLimitGradientOptimisationScreen::~OneLimitGradientOptimisationScreen()
{
}
