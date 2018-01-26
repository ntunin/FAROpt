#pragma once
#include "OptimisationAlgoritm.h"

class HGSAAlgoritm:
	public OptimisationAlgoritm {
protected:
	double TInitial;
	double coolDownSpeed;
	double radius;
	void getRandomOffset(double *xM, double *x, int size, double radius);
	void coppyValues(double *x, double *xM, int size);
public:
	void solve();
	HGSAAlgoritm();
	~HGSAAlgoritm();
};

