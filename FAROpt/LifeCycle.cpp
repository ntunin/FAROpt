#include "stdafx.h"
#include "LifeCycle.h"

using namespace std;

LifeCycle::LifeCycle()
{
}


LifeCycle::~LifeCycle()
{
}

void LifeCycle::printMain() {
	reset();
	print("---- FAR Optimisation ----\n");
	print("----   Omsk, 2017     ----\n");
	print("\n");
	print("Select the action you want to apply:\n");
	print("   1: 1-Limited optimisation\n");
	print("   2: Full-Limited optimisation\n");
	print("   3: FAR builder\n");
	print("   0: exit\n\n");
}

void LifeCycle::run() {
	this->finished = false;
	while (!this->finished) {
		printMain();
		int action = readInt("Enter your choice: > ");
		switch (action) {
		case 1:
			OneLimitOptimisationMenuScreen();
			break;
		case 2:
			FullLimitOptimisationMenuScreen();
			break;
		case 3:
			FARBuilderScreen();
			break;
		case 0:
			this->exit();
		}
	}
}

void LifeCycle::exit() {
	this->finished = true;
}
