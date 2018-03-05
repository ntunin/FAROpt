#pragma once
#include "ComplexVector.h"

class FAROptimisationAlgoritm {
public:
	FAROptimisationAlgoritm();
	~FAROptimisationAlgoritm();
	void set_uAu(double uAu);
	void set_uBu(std::vector<double> *uBu); 
	std::vector<double> *get_uBu();
	void setD(double D);
	void setV(int n, double *vEx);
	double get_uAu();
	double getD();
	ComplexVector *getV();
	std::vector<double> start;
private:
	double uAu;
	std::vector<double> *uBu;
	double d;
	ComplexVector *v;
};

