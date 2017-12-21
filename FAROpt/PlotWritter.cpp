#include "stdafx.h"
#include "PlotWritter.h"

using namespace std;


PlotWritter::PlotWritter(string name, NecOut *out, double theta, double phi) {
	this->name = name;
	this->out = out;
	this->theta = theta;
	this->phi = phi;
	ofstream file(this->name);
	this->writeStream(file);
	file.close();
}


void PlotWritter::writeStream(ofstream &stream) {
	vector<NecOut::RadiationPattern> patterns = this->out->getRadiationPatterns();
	int length = patterns.size();
	stream << "#   theta                      phi                   gain                        magnitude                  phase" << endl;
	for (int i = 0; i < length; i++) {
		NecOut::RadiationPattern pattern = patterns[i];
		double theta = pattern.getTheta();
		double phi = pattern.getPhi();
		if (abs(theta - this->theta) < 1e-4) {
			stream << pattern.getTheta() << "   " << pattern.getPhi() + 45 << "   " << pattern.getGain() << "   " << pattern.getMagnitude() << "   " << pattern.getPhase() << endl;
		}
	}
}

PlotWritter::~PlotWritter()
{
}
