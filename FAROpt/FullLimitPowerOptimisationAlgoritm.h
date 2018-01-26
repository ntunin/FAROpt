#pragma once
#include "FullLimitOptimisationAlgoritm.h"
class FullLimitPowerOptimisationAlgoritm :
	public FullLimitOptimisationAlgoritm
{
protected:
	std::vector<double **> *calculateB(OptimisationEnvirounment *envirounment);
	std::vector<double> *P;
public:
	FullLimitPowerOptimisationAlgoritm();
	~FullLimitPowerOptimisationAlgoritm();
};

