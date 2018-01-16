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

FAROptimisationAlgoritm *LamdaGainOptimisationScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	return new LamdaGainOptimisationAlgoritm(envirounment);
}

LamdaGainOptimisationScreen::~LamdaGainOptimisationScreen() {
}
