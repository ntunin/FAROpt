#pragma once
#include "OptimisationAlgoritm.h"
class GradientSAAlgoritm :
	public OptimisationAlgoritm
{
protected:
	double TInitial;
	double coolDownSpeed;
	double radius;
	void getRandomOffset(double *xM, double *x, int size, double radius);
	void coppyValues(double *x, double *xM, int size);
	void push(double **stack, double *newVector, int stackSize, int vectorSize);
public:
	GradientSAAlgoritm();
	void solve();
	virtual void getGradient(double *x, double *dF, int size) = 0;
	~GradientSAAlgoritm();
};

