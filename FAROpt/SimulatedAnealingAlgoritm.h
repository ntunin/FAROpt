#pragma once
#include "OptimisationAlgoritm.h"

class SimulatedAnealingAlgoritm:
	public OptimisationAlgoritm {
protected:
	double TInitial;
	double coolDownSpeed;
	double radius;
public:
	void solve();
	SimulatedAnealingAlgoritm();
	~SimulatedAnealingAlgoritm();
};

