#include "stdafx.h"
#include "BHandler.h"

using namespace std;

BHandler::BHandler() {
	this->setKeywords("- - B - -");
}

void BHandler::readContent(ifstream *file, FileStructure *structure) {
	CheckoutData *data = (CheckoutData *)structure;
	string buffer = "error";
	TableValueParser p = TableValueParser(buffer);
	vector<double **> *B = new vector<double **>;
	bool externalRunning = true;
	while (externalRunning) {
		vector<double> line;
		int size = 0;
		bool running = true;
		while (running) {
			getline(*file, buffer);
			if (buffer.length() < 4) {
				running = false;
				break;
			}
			if (buffer.find("- -") != string::npos) {
				externalRunning = false;
				running = false;
				break;
			}
			p.setInput(buffer);
			size++;
			while (!p.isEmpty()) {
				double value = p.getDouble(true);
				line.push_back(value);
			}
		}
		if (externalRunning) {
			double **Bi = new double*[size];
			for (int i = 0; i < size; i++) {
				Bi[i] = new double[size];
				for (int j = 0; j < size; j++) {
					Bi[i][j] = line[i*size + j];
				}
			}
			B->push_back(Bi);
			data->setSizeIfNotOutOfBound(size);
		}	
	}
	data->setB(B);
}

BHandler::~BHandler()
{
}
