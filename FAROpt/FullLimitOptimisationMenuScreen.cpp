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
	print("   1: Simulated annealing optimisation of directivity\n");
	print("   0: exit\n\n");
}

void FullLimitOptimisationMenuScreen::run() {
	while (true) {
		printHead();
		int action = readInt("Enter your choice: > ");
		switch (action) {
		case 0:
			return;
		}
	}
}


FullLimitOptimisationMenuScreen::~FullLimitOptimisationMenuScreen()
{
}
