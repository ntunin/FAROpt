#pragma once
#include "ComplexVector.h"
#include "FAROptimisationAlgoritm.h"
#define PI 3.14159265359
class OneLimitOptimisationAlgoritm: public FAROptimisationAlgoritm {
public:
	OneLimitOptimisationAlgoritm();
	~OneLimitOptimisationAlgoritm();
protected:
	int size;
	double *vEx;
	double **B;
	double **AEx;
	virtual double **calculateB(OptimisationEnvirounment *envirounment) = 0;
	double calculate_uAu(double *vEx);
	double calculate_uBu(double *vEx);
	void solveOneLimitOptimisationTask(OptimisationEnvirounment *envirounment);
	virtual void solveOptimisationTask(OptimisationEnvirounment *envirounment) = 0;
private:
	double uBu;
};

