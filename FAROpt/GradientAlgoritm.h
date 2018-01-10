#pragma once
class GradientAlgoritm
{
private:
	bool maximisation;
	int size;
	double *x;
public:
	GradientAlgoritm();
	virtual double targetFunction(double *x) = 0;
	void solve();
	void setSize(int size);
	void makeMaximisational();
	void setInitial(double *x);
	~GradientAlgoritm();
};

