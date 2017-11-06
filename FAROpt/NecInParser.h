#pragma once
#include <fstream>
#include <vector>
#include "NecIn.h"
#include "FileParser.h"
#include "StringHandler.h"

class NecInParser: FileParser {
public:
	NecInParser(std::string &fileName, NecIn *in);
	~NecInParser();
protected:
	void readFile(std::ifstream *file);
private: 
	void searchContentByKeywordsHandlers(std::ifstream *file, int handlersCount, StringHandler **handlers);
	NecIn *in;
};

