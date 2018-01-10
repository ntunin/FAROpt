#pragma once
#include "ProcessRunner.h"
#include "NecOut.h"

class NecOutPlotDrawer :
	public ProcessRunner
{
public:
	NecOutPlotDrawer();
	NecOutPlotDrawer(NecOut *out, double theta, double phi);
	~NecOutPlotDrawer();
	void dispatch();
private:
	NecOut *out;
	double theta;
	double phi;
};

