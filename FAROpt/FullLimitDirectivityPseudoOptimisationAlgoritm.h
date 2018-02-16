#pragma once
#include "FullLimitPowerOptimisationAlgoritm.h"
#include "OptimisationEnvirounment.h"
#include "LamdaOptimisationAlgoritm.h"

class FullLimitDirectivityPseudoOptimisationAlgoritm :
	public FullLimitPowerOptimisationAlgoritm,
	public LamdaOptimisationAlgoritm {
public:
	void solveOptimisationTask(OptimisationEnvirounment *envirounment);
	FullLimitDirectivityPseudoOptimisationAlgoritm(OptimisationEnvirounment *envirounment, std::vector<double> *P);
	~FullLimitDirectivityPseudoOptimisationAlgoritm();
};

