#include "stdafx.h"
#include "PredefinedScanner.h"

using namespace std;

PredefinedScanner::PredefinedScanner() {
	this->index = 0;
	this->offset = 1;
	this->results.push_back("2");
	this->results.push_back("2");
	this->results.push_back("3x3WWD.nec");
	this->results.push_back("70");
	this->results.push_back("45");
	this->results.push_back("y");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("100");
	this->results.push_back("1");
	this->results.push_back("1");
	this->results.push_back("5000000");
	this->results.push_back("4");
	this->results.push_back("0");
	this->results.push_back("0");
}

std::stringstream PredefinedScanner::next() {
	std::string result;
	int size = results.size();
	int i = (this->index + size) % size;
	if (i == 0) {
		this->index = 0;
	}
	result = this->results[i];
	this->index++;
	return stringstream(result);
}


PredefinedScanner::~PredefinedScanner()
{
}


int PredefinedScanner::readInt(std::string message) {
	int result;
	Shared::bundle().log()->print(message);
	next() >> result;
	Shared::bundle().log()->print(result);
	Shared::bundle().log()->print("\n");
	return result;
}

int PredefinedScanner::readInt() {
	int result;
	next() >> result;
	return result;
}

double PredefinedScanner::readDouble(std::string message) {
	double result;
	Shared::bundle().log()->print(message);
	next() >> result;
	Shared::bundle().log()->print(result);
	Shared::bundle().log()->print("\n");
	return result;
}

double PredefinedScanner::readDouble() {
	double result;
	next() >> result;
	return result;
}


string PredefinedScanner::readString(std::string message) {
	string result;
	Shared::bundle().log()->print(message);
	next() >> result;
	Shared::bundle().log()->print(result);
	Shared::bundle().log()->print("\n");
	return result;
}

string PredefinedScanner::readString() {
	string result;
	next() >> result;
	return result;
}


bool PredefinedScanner::readBool() {
	std::string answer;
	next() >> answer;
	while (true) {
		switch (answer[0]) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			break;
		}
		next() >> answer;
	}
}

bool PredefinedScanner::readBool(string message) {
	std::string answer;
	Shared::bundle().log()->print(message);
	Shared::bundle().log()->print(" (y / n): >");
	next() >> answer;
	Shared::bundle().log()->print(answer);
	Shared::bundle().log()->print("\n");
	while (true) {
		switch (answer[0]) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			break;
		}
		Shared::bundle().log()->print("Sorry, entered invalid case. Required 'y' or 'n': >");
		next() >> answer;
	}
}
