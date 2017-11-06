#pragma once
#include <fstream>
#include <vector>
#include "NecOut.h"
#include "FileParser.h"
#include "FileStreamHandler.h"



class NecOutParser: FileParser {
public:
	NecOutParser(std::string &filename, NecOut *out);
	~NecOutParser();
private:
	NecOut *out;
	void searchContentByKeywordsHandlers(std::ifstream *file, int handlersCount, FileStreamHandler **handlers);
protected:
	void readFile(std::ifstream *file);
};