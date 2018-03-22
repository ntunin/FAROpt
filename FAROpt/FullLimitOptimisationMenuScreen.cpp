#include "stdafx.h"
#include "FullLimitOptimisationMenuScreen.h"


FullLimitOptimisationMenuScreen::FullLimitOptimisationMenuScreen() {
	printHead();
	run();
}

void FullLimitOptimisationMenuScreen::printHead() {
	reset();
	print("---- Full Limited Optimisation ----\n");
	print("----   Omsk, 2018     ----\n");
	print("\n");
	print("Select the action you want to apply:\n");
	print("   1: Pseudo-optimisation besedon lamda algoithm\n");
	print("   2: Hooke - Jeeves optimisation of input power\n");
	print("   3: Simulated annealing based on Hooke - Jeeves multy-threads optimisation of input power\n");
	print("   4: Simulated annealing based on Gradient optimisation of input power\n");
	print("   5: Hooke - Jeeves multy-threads optimisation of input power\n");
	print("   6: Simulated annealing based on Gradient multy-threads optimisation of input power\n");
	print("   7: Check provided solution\n");
	print("   0: exit\n\n");
}

void FullLimitOptimisationMenuScreen::run() {
	while (true) {
		printHead();
		int action = readInt("Enter your choice: > ");
		switch (action) {
		case 1: {
			FullLimitDirectivityPseudoOptimisationScreen();
			break;
		}
		case 2: {
			FullLimitPowerOptimisationHGScreen();
			break;
		}
		case 3: {
			FullLimitMultyThreadPowerOptimisationHGSAScreen();
			break;
		}
		case 4: {
			FullLimitPowerOptimisationGradientSAScreen();
			break;
		}
		case 5: {
			FullLimitMultyThreadPowerOptimisationHGScreen();
			break;
		}
		case 6: {
			FullLimitMultyThreadPowerOptimisationGradientSAScreen();
			break;
		}
		case 7: {
			CheckProvidedSolutionScreen();
			break;
		}
		case 0:
			return;
		}
	}
}


FullLimitOptimisationMenuScreen::~FullLimitOptimisationMenuScreen()
{
}
