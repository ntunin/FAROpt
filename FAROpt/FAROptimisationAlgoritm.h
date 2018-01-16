#pragma once
#include "ComplexVector.h"

class FAROptimisationAlgoritm {
public:
	FAROptimisationAlgoritm();
	~FAROptimisationAlgoritm();
	void set_uAu(double uAu);
	void setD(double D);
	void setV(int n, double *vEx);
	double get_uAu();
	double getD();
	ComplexVector *getV();
private:
	double uAu;
	double uBu;
	double d;
	ComplexVector *v;
};
