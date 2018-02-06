#pragma once
#include "ConsoleScreen.h"
#include "CheckoutData.h"

class CheckProvidedSolutionScreen :
	public ConsoleScreen
{
private:
	double calculate_uAu(double *vEx);
	std::vector<double> *calculate_uBu(double *vEx);
	CheckoutData *data;
protected:
	void printHead();
public:
	CheckProvidedSolutionScreen();
	~CheckProvidedSolutionScreen();
};

