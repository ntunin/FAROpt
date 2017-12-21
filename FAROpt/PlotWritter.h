#pragma once
#include "NecOut.h"


class PlotWritter
{
private: 
	std::string name;
	NecOut *out;
	void writeStream(std::ofstream &stream); 
	double theta; 
	double phi;
public:
	PlotWritter(std::string name, NecOut *out, double theta, double phi);
	~PlotWritter();
};

