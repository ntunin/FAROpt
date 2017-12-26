#pragma once
#define PI 3.14159265359
class LamdaOptimisationAlgoritm
{
private:
public:
	void set_uAu(double uAu);
	void set_uBu(double uBu);
	void setD(double D);
	void setV(int n, double *vEx);
	double get_uAu();
	double get_uBu();
	double getD();
	ComplexVector *getV();
private:
	double uAu;
	double uBu;
	double d;
	ComplexVector *v;

public:
	LamdaOptimisationAlgoritm();
	~LamdaOptimisationAlgoritm();
};

