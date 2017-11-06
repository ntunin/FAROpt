#pragma once
#include <string>
#include "NecCommand.h"

class RP: public NecCommand {
public:
	RP(int mode, int thetaNumber, int phiNumber, std::string XNDA,	double theta0, double phi0, double thetaInc, double phiInc);
	RP(RP &rp);
	~RP();
	std::string toString();
private:
	int mode;
	int thetaNumber;
	int phiNumber;
	std::string XNDA;
	double theta0;
	double phi0;
	double thetaInc;
	double phiInc;
};

