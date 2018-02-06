#include "stdafx.h"
#include "XHandler.h"

using namespace std;

XHandler::XHandler() {
	this->setKeywords("- - X - -");
}

void XHandler::readContent(ifstream *file, FileStructure *structure) {
	CheckoutData *data = (CheckoutData *)structure;
	string buffer = "error";
	TableValueParser p = TableValueParser(buffer);
	vector<double> line;
	int size = 0;
	while (true) {
		getline(*file, buffer);
		if (buffer == "" || buffer == "\n") break;
		p.setInput(buffer);
		while (!p.isEmpty()) {
			double value = p.getDouble(true);
			line.push_back(value);
			size++;
		}
	}
	double *X = new double[size];
	for (int i = 0; i < size; i++) {
		X[i] = line[i];
	}
	data->setX(X);
	data->setSizeIfNotOutOfBound(size);
}


XHandler::~XHandler() {
}
