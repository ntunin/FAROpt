#include "stdafx.h"
#include "CheckoutParser.h"
#include "AHandler.h"
#include "BHandler.h"
#include "XHandler.h"

using namespace std;

CheckoutParser::CheckoutParser(std::string &fileName, CheckoutData *data) {
	this->data = data;
	this->parse(fileName);
}


FileStreamHandler **CheckoutParser::createHandlers(int &count) {
	count = 3;
	FileStreamHandler **handlers = new FileStreamHandler*[count] {
		(FileStreamHandler *)(new AHandler()),
		(FileStreamHandler *)(new BHandler()),
		(FileStreamHandler *)(new XHandler())
	};
	return handlers;
}

void CheckoutParser::removeHandlers(int count, FileStreamHandler **handlers) {
	for (int i = 0; i < count; i++) {
		delete handlers[i];
	}
	delete handlers;
}

void CheckoutParser::readFile(ifstream *file) {
	int count;
	FileStreamHandler **handlers = createHandlers(count);
	this->searchContentByKeywordsHandlers(file, count, handlers);
	removeHandlers(count, handlers);
}



CheckoutParser::~CheckoutParser() {
}


void CheckoutParser::searchContentByKeywordsHandlers(ifstream *file, int handlersCount, FileStreamHandler **handlers) {
	string buffer;
	while (!file->eof()) {
		getline(*file, buffer);
		for (int i = 0; i < handlersCount; i++) {
			if (handlers[i]->checkString(buffer)) {
				handlers[i]->readContent(file, this->data);
			}
		}
	}
}