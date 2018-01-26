#include "stdafx.h"
#include "OneLimitHGSAScreen.h"


OneLimitHGSAScreen::OneLimitHGSAScreen() {
	this->apply();
}


void OneLimitHGSAScreen::printHead() {
	print("---- 1-Limited simulated anealing based on Hooke - Jeeves optimisation algoritm ----\n");
	print("----                Omsk, 2018                ----\n");
	print("\n");
}

FAROptimisationAlgoritm *OneLimitHGSAScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	double T = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"temperature\" of the system: >");
	double speed = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"cool down speed\" of the system: >");
	double radius = Shared::bundle().scanner()->readDouble("\nPlease, enter the \"random offset radius\": >");
	return new OneLimitHGSAOptimisationAlgoritm(envirounment, T, speed, radius);
}


OneLimitHGSAScreen::~OneLimitHGSAScreen()
{
}
