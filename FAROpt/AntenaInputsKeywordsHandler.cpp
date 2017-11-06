#include "stdafx.h"
#include "AntenaInputsKeywordsHandler.h"

using namespace std;

AntenaInputsKeywordsHandler::~AntenaInputsKeywordsHandler()
{
}

AntenaInputsKeywordsHandler::AntenaInputsKeywordsHandler() {
	this->setKeywords("ANTENNA INPUT PARAMETERS");
}


void AntenaInputsKeywordsHandler::readContent(ifstream *file, FileStructure *structure) {
	NecOut *out = (NecOut *)structure;
	skip(file, 3); // Skip empty lines and legend
	string buffer = "error";
	TableValueParser p = TableValueParser(buffer);
	while (buffer != "") {
		getline(*file, buffer);
		p.setInput(buffer);
		int tag = p.getInt();
		int seg = p.getInt();
		double vRe = p.getDouble();
		double vIm = p.getDouble();
		double iRe = p.getDouble();
		double iIm = p.getDouble();
		double zRe = p.getDouble();
		double zIm = p.getDouble();
		double aRe = p.getDouble();
		double aIm = p.getDouble();
		double power = p.getDouble();
		out->addSource(tag, seg, vRe, vIm, iRe, iIm, zRe, zIm, aRe, aIm, power);
	}
}
