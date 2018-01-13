#include "stdafx.h"
#include "OneLimitOptimisationMenuScreen.h"


OneLimitOptimisationMenuScreen::OneLimitOptimisationMenuScreen() {
	printHead();
}

void OneLimitOptimisationMenuScreen::printHead() {
	reset();
	print("---- One Limited Optimisation ----\n");
	print("----   Omsk, 2018     ----\n");
	print("\n");
	print("Select the action you want to apply:\n");
	print("   1: Lamda-optimisation of directivirty\n");
	print("   2: Lamda-optimisation of gain\n");
	print("   3: Gradient optimisation of directivity\n");
	print("   4: Sumulated annealing optimisation of directivity\n");
	print("   0: exit\n\n");
}

void OneLimitOptimisationMenuScreen::run() {
	while (true) {
		printHead();
		int action = readInt("Enter your choice: > ");
		switch (action) {
		case 1:
			LamdaDirectivityOptimisationScreen();
			break;
		case 2:
			LamdaGainOptimisationScreen();
			break;
		case 3:
			OneLimitGradientOptimisationScreen();
			break;
		case 0:
			return;
		}
	}
}


OneLimitOptimisationMenuScreen::~OneLimitOptimisationMenuScreen()
{
}
