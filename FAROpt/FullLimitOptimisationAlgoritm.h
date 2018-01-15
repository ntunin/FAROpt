#pragma once
class FullLimitOptimisationAlgoritm
{

public:
	FullLimitOptimisationAlgoritm();
	~FullLimitOptimisationAlgoritm();
	void set_uAu(double uAu);
	void setD(double D);
	void setV(int n, double *vEx);
	double get_uAu();
	double getD();
	ComplexVector *getV();
private:
	double uAu;
	double d;
	ComplexVector *v;
};

