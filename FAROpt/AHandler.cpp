#include "stdafx.h"
#include "AHandler.h"

using namespace std;

AHandler::AHandler() {
	this->setKeywords("- - A - -");
}

void AHandler::readContent(ifstream *file, FileStructure *structure) {
	CheckoutData *data = (CheckoutData *)structure;
	string buffer = "error";
	TableValueParser p = TableValueParser(buffer);
	vector<double> line;
	int size = 0;
	while (true) {
		getline(*file, buffer);
		if (buffer == "" || buffer == "\n") break;
		p.setInput(buffer);
		size++;
		while (!p.isEmpty()) {
			double value = p.getDouble(true);
			line.push_back(value);
		}
	}
	double **A = new double*[size];
	for (int i = 0; i < size; i++) {
		A[i] = new double[size];
		for (int j = 0; j < size; j++) {
			A[i][j] = line[i*size + j];
		}
	}
	data->setA(A);
	data->setSizeIfNotOutOfBound(size);
}


AHandler::~AHandler()
{
}
