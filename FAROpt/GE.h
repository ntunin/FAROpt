#pragma once
#include "NecCommand.h"

class GE: public NecCommand {
public:
	GE(int falg);
	GE(GE &ge);
	~GE();
	std::string toString();
private:
	int flag;

};
