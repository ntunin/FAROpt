#include "stdafx.h"
#include "LamdaGainOptimisationScreen.h"


using namespace std;

LamdaGainOptimisationScreen::LamdaGainOptimisationScreen() {
	this->apply();
}

void LamdaGainOptimisationScreen::printHead() {
	print("---- 1-Limited old lamda-optimisation algoritm----\n");
	print("----                Omsk, 2017                ----\n");
	print("\n");
}

OneLimitOptimisationAlgoritm *LamdaGainOptimisationScreen::getAgoritm(OneLimitOptimisationEnvirounment *envirounment) {
	return new LamdaGainOptimisationAlgoritm(envirounment);
}

LamdaGainOptimisationScreen::~LamdaGainOptimisationScreen() {
}
