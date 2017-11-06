#include "stdafx.h"
#include "GEHandler.h"

using namespace std;

GEHandler::GEHandler() {
	this->setKeywords("GE");
}


GEHandler::~GEHandler() {
}

void GEHandler::readContent(string str, FileStructure *structure) {
	NecIn *in = (NecIn *)structure;
	str.erase(0, str.find("GE") + 2);
	TableValueParser p = TableValueParser(str);
	int flag = p.getInt();
	GE ge = GE(flag);
	in->setGE(ge);
}

