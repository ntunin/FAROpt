#pragma once
#include "FileStructure.h"
class CheckoutData :
	public FileStructure
{
private:
	double **A;
	std::vector<double **> *B;
	double *X;
	int size;
public:
	int getSize();
	void setSizeIfNotOutOfBound(int size);
	double **getA();
	std::vector<double **> *getB();
	double *getX();
	void setA(double **A);
	void setB(std::vector<double **> *B);
	void setX(double *X);
	CheckoutData();
	~CheckoutData();
};

