#pragma once
#include "FileParser.h"
#include "CheckoutData.h"
#include "FileStreamHandler.h"

class CheckoutParser :
	public FileParser {
public:
	CheckoutParser(std::string &filename, CheckoutData *data);
	~CheckoutParser();
private:
	CheckoutData * data;
	void searchContentByKeywordsHandlers(std::ifstream *file, int handlersCount, FileStreamHandler **handlers);
	FileStreamHandler **createHandlers(int &count);
	void removeHandlers(int count, FileStreamHandler **handlers);
protected:
	void readFile(std::ifstream *file);
};

