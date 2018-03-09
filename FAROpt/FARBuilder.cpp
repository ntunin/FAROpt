#include "stdafx.h"
#include "FARBuilder.h"
#include "NecIn.h"
#include "NecInParser.h"

using namespace std;

FARBuilder::FARBuilder(std::string tamplateFileName, std::string antennaFileName, int width, int height, double xStep, double yStep, double voltage) {
	NecIn *fileTemplate = new NecIn;
	NecInParser(tamplateFileName, fileTemplate);
	NecIn *antennaTemplate = new NecIn;
	NecInParser(antennaFileName, antennaTemplate);
	vector<GW *> wires;
	vector<GW *> templateWires = *(antennaTemplate->getGW());
	vector<EX *> tamplateEX = *(antennaTemplate->getEX());
	int n = 0;
	for (double x = -width*xStep/2; x < width*xStep/2; x+=xStep) {
		for (double y = -height * yStep / 2; y < height*yStep / 2; y += yStep) {
			for (int i = 0; i < templateWires.size(); i++) {
				n++;
				GW *gw = new GW(*templateWires[i]);
				double a = atan(y / x);
				gw->translate(x, y, 0);
				gw->rotateZ(a);
				gw->setTag(100 + n);
			}
		}
	}
}


FARBuilder::~FARBuilder()
{
}
