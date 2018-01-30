#include "stdafx.h"
#include "OneLimitGradientSAOptimisationScreen.h"


OneLimitGradientSAOptimisationScreen::OneLimitGradientSAOptimisationScreen() {
	this->apply();
}


void OneLimitGradientSAOptimisationScreen::printHead() {
	print("---- 1-Limited simulated anealing based on gradient optimisation algoritm ----\n");
	print("----                Omsk, 2018                ----\n");
	print("\n");
}

FAROptimisationAlgoritm *OneLimitGradientSAOptimisationScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	double T = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"temperature\" of the system: >");
	double speed = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"cool down speed\" of the system: >");
	double radius = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"random offset radius\": >");
	double mulctMultiplier = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" multiplier: >");
	double mulctDegree = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"mulct\" degree: >");
	return new OneLimitGradientSAOptimisationAlgoritm(envirounment, T, speed, radius, mulctMultiplier, mulctDegree);
}



OneLimitGradientSAOptimisationScreen::~OneLimitGradientSAOptimisationScreen()
{
}
