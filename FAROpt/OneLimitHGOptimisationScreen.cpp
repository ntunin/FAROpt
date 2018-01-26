#include "stdafx.h"
#include "OneLimitHGOptimisationScreen.h"



OneLimitHGOptimisationScreen::OneLimitHGOptimisationScreen() {
	this->apply();
}

void OneLimitHGOptimisationScreen::printHead() {
	print("---- 1-Limited Hooke - Jeeves optimisation algoritm ----\n");
	print("----                Omsk, 2017                ----\n");
	print("\n");
}

FAROptimisationAlgoritm *OneLimitHGOptimisationScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	return new OneLimitHGOptimisationAlgoritm(envirounment);
}

OneLimitHGOptimisationScreen::~OneLimitHGOptimisationScreen()
{
}
