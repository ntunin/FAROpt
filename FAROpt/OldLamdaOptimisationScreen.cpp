#include "stdafx.h"
#include "OldLamdaOptimisationScreen.h"


using namespace std;

OldLamdaOptimisationScreen::OldLamdaOptimisationScreen() {
	this->apply();
}

void OldLamdaOptimisationScreen::printHead() {
	print("---- 1-Limited old lamda-optimisation algoritm----\n");
	print("----                Omsk, 2017                ----\n");
	print("\n");
}

OneLimitOptimisationAlgoritm *OldLamdaOptimisationScreen::getAgoritm(OneLimitOptimisationEnvirounment *envirounment) {
	return new OldLamdaOptimisationAlgoritm(envirounment);
}

OldLamdaOptimisationScreen::~OldLamdaOptimisationScreen() {
}
