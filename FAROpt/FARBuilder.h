#pragma once
class FARBuilder
{
public:
	FARBuilder(std::string tamplateFileName, std::string antennaFileName, int width, int height, double xStep, double yStep, double voltage);
	~FARBuilder();
};

