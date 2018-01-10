#include "stdafx.h"
#include "NewLamdaOptimisationScreen.h"

using namespace std;

NewLamdaOptimisationScreen::NewLamdaOptimisationScreen() {
	this->apply();
}

void NewLamdaOptimisationScreen::printHead() {
	print("---- 1-Limited new lamda-optimisation algoritm----\n");
	print("----                Omsk, 2017                ----\n");
	print("\n");
}

OneLimitOptimisationAlgoritm *NewLamdaOptimisationScreen::getAgoritm(OneLimitOptimisationEnvirounment *envirounment) {
	return new NewLamdaOptimisationAlgoritm(envirounment);
}

NewLamdaOptimisationScreen::~NewLamdaOptimisationScreen()
{
}
