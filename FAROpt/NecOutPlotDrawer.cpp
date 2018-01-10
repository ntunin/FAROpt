#include "stdafx.h"
#include "NecOutPlotDrawer.h"

using namespace std;

NecOutPlotDrawer::NecOutPlotDrawer() {

}

NecOutPlotDrawer::NecOutPlotDrawer(NecOut *out, double theta, double phi) {
	this->out = out;
	this->theta = theta;
	this->phi = phi;
	this->createThread();
}

void NecOutPlotDrawer::dispatch() {
	PlotWritter("2plot.dat", this->out, this->theta, this->phi);
	this->exe(string("gnuplot  --persist plot.ctl"));
}


NecOutPlotDrawer::~NecOutPlotDrawer()
{
}
