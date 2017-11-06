#pragma once
#include "NecIn.h"
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h> 

class OneSourceNecInWritter {

private:
	void writeStream(std::ofstream &stream);
	int sourceNumber;
	NecIn *in;
	std::string name;

public:
	OneSourceNecInWritter(int sourceNumber, NecIn *in, std::string name);
	~OneSourceNecInWritter();
};

