#pragma once
#include "NecCommand.h"

class GW: public NecCommand {
public:
	GW(int tag, int seg, double x1, double y1, double z1, double x2, double y2, double z2, double radius);
	std::string toString();
	GW(GW &GW);
	~GW();
private:
	int tag;
	int seg;
	double x1;
	double y1;
	double z1;
	double x2;
	double y2;
	double z2;
	double radius;
};

