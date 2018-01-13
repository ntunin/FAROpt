#pragma once
#include "OptimisationAlgoritm.h"

class SimulatedAnealingAlgoritm:
	public OptimisationAlgoritm {
public:
	void solve();
	SimulatedAnealingAlgoritm();
	~SimulatedAnealingAlgoritm();
};

