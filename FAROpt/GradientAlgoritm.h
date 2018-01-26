#pragma once
#include "OptimisationAlgoritm.h"
class GradientAlgoritm :
	public OptimisationAlgoritm
{
public:
	GradientAlgoritm();
	void solve();
	virtual void getGradient(double *x, double *dF, int size) = 0;
	~GradientAlgoritm();
};

