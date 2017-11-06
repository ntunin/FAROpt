#pragma once
#include <string>
class NecCommand {
public:
	NecCommand();
	~NecCommand();
	virtual std::string toString() = 0;
	std::string toString(int value, int stringSize);
	std::string toString(double value, int stringSize);
	std::string toString(double value, int stringSize, bool exp);
};

