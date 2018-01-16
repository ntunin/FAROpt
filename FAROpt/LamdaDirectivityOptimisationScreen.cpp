#include "stdafx.h"
#include "LamdaDirectivityOptimisationScreen.h"

using namespace std;

LamdaDirectivityOptimisationScreen::LamdaDirectivityOptimisationScreen() {
	this->apply();
}

void LamdaDirectivityOptimisationScreen::printHead() {
	print("---- 1-Limited lamda-optimisation of directivity ----\n");
	print("----                 Omsk, 2017                  ----\n");
	print("\n");
}

FAROptimisationAlgoritm *LamdaDirectivityOptimisationScreen::getAgoritm(OptimisationEnvirounment *envirounment) {
	return new LamdaDirectivityOptimisationAlgoritm(envirounment);
}

LamdaDirectivityOptimisationScreen::~LamdaDirectivityOptimisationScreen()
{
}
