#pragma once
#include "Complex.h"
#include "NecCommand.h"

class EX : public NecCommand {
private:
	int type;
	int tag;
	int seg;
	int admittance;
	Complex value;
public:
	EX(int type, int tag, int seg, int admittance, double valueRe, double valueIm);
	EX(EX &ex);
	EX(EX &ex, Complex &source);
	EX(EX &ex, bool disabled);
	~EX();
	std::string toString();
	Complex &getValue();
};

