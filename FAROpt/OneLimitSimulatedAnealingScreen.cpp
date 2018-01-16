#include "stdafx.h"
#include "OneLimitSimulatedAnealingScreen.h"


OneLimitSimulatedAnealingScreen::OneLimitSimulatedAnealingScreen() {
	this->apply();
}


void OneLimitSimulatedAnealingScreen::printHead() {
	print("---- 1-Limited simulated anealing optimisation algoritm ----\n");
	print("----                Omsk, 2018                ----\n");
	print("\n");
}

FAROptimisationAlgoritm *OneLimitSimulatedAnealingScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	double T = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"temperature\" of the system: >");
	double speed = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"cool down speed\" of the system: >");
	double radius = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"random offset radius\": >");
	return new OneLimitSimulatedAnealingOptimisationAlgoritm(envirounment, T, speed, radius);
}


OneLimitSimulatedAnealingScreen::~OneLimitSimulatedAnealingScreen()
{
}
