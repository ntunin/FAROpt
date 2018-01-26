#pragma once
#include "FAROptimisationAlgoritm.h"
#include <vector>

class FullLimitOptimisationAlgoritm: public FAROptimisationAlgoritm
{

public:
	FullLimitOptimisationAlgoritm();
	~FullLimitOptimisationAlgoritm();
protected:
	int size;
	double *vEx;
	std::vector<double **> *B;
	double **AEx;
	virtual std::vector<double **> *calculateB(OptimisationEnvirounment *envirounment) = 0;
	double calculate_uAu(double *vEx);
	std::vector<double> *calculate_uBu(double *vEx);
	void solveFullLimitOptimisationTask(OptimisationEnvirounment *envirounment);
	virtual void solveOptimisationTask(OptimisationEnvirounment *envirounment) = 0;
};

