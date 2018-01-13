#pragma once
class OptimisationAlgoritm
{
private:
	bool maximisation;
	int size;
	double *x;
public:
	OptimisationAlgoritm();
	virtual double targetFunction(double *x) = 0;
	void setSize(int size);
	void makeMaximisational();
	bool isMaximisational();
	void setInitial(double *x);
	double *getCurrentSolution();
	int getSize();
	~OptimisationAlgoritm();
};

