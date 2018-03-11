#include "stdafx.h"
#include "FARBuilder.h"
#include "NecIn.h"
#include "NecInParser.h"
#include "NecInWritter.h"

using namespace std;

double getAngle(double x, double y) {
	if (x > 0) {
		if (y >= 0) {
			return atan(y / x);
		}
		return atan(y / x) + 2 * PI;
	} 
	if (x < 0) {
		return atan(y / x) + PI;
	}
	if (y > 0) {
		return PI / 2;
	}
	if (y < 0) {
		return 3 * PI / 2;
	}
	return 0;
}

FARBuilder::FARBuilder(std::string tamplateFileName, std::string antennaFileName, std::string targetFileName, int width, int height, double xStep, double yStep, double voltage) {
	NecIn *fileTemplate = new NecIn;
	NecInParser(tamplateFileName, fileTemplate);
	NecIn *antennaTemplate = new NecIn;
	NecInParser(antennaFileName, antennaTemplate);
	vector<GW *> *wires = new vector<GW *>;
	vector<GW *> templateWires = *(antennaTemplate->getGW());
	vector<EX *> *sources = new vector<EX *>;
	vector<EX *> templateEX = *(antennaTemplate->getEX());
	int n = 0;
	for (double y = (-height + 1) * yStep / 2; y <= (height - 1)*yStep / 2; y += yStep) {
		for (double x = (-width + 1)*xStep/2; x <= (width - 1)*xStep/2; x+=xStep) {
			double a = getAngle(x, y);
			for (int i = 0; i < templateWires.size(); i++) {
				n++;
				GW *gw = new GW(*templateWires[i]);
				gw->rotateZ(a - 0.78);
				gw->translate(x, y, 0);
				int newTag = 100 + n;
				for (int j = 0; j < templateEX.size(); j++) {
					EX *ex = templateEX[j];
					if (ex->getTag() == gw->getTag()) {
						EX *newEX = new EX(*ex);
						newEX->setTag(newTag);
						sources->push_back(newEX);
					}
				}
				gw->setTag(100 + n);
				wires->push_back(gw);
			}
		}
	}
	fileTemplate->setEX(sources);
	fileTemplate->setGW(wires);
	NecInWritter(fileTemplate, targetFileName);
}


FARBuilder::~FARBuilder()
{
}
