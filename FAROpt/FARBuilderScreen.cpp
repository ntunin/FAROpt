#include "stdafx.h"
#include "FARBuilderScreen.h"
#include "FARBuilder.h"

using namespace std;

FARBuilderScreen::FARBuilderScreen() {
	reset();
	print("---- FAR Builder ----\n");
	print("----   Omsk, 2018     ----\n");
	print("\n");
	string templateName = Shared::bundle().scanner()->readString("Envirounment template *.nec file: > ");
	string antennaName = Shared::bundle().scanner()->readString("Antenna template *.nec file: > ");
	string outName = Shared::bundle().scanner()->readString("Output *.nec file: > ");
	int width = Shared::bundle().scanner()->readInt("Count by horisontal: > ");
	int height = Shared::bundle().scanner()->readInt("Count by vertical: > ");
	double xStep = Shared::bundle().scanner()->readDouble("Space between by horisontal: > ");
	double yStep = Shared::bundle().scanner()->readDouble("Space between by vertical: > ");
	double voltage = Shared::bundle().scanner()->readDouble("Voltage per source: > ");
	FARBuilder(templateName, antennaName, outName, width, height, xStep, yStep, voltage);
	Shared::bundle().log()->print("\nDone\n");
	system("pause");
}


FARBuilderScreen::~FARBuilderScreen()
{
}
