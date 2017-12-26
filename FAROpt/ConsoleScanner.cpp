#include "stdafx.h"
#include "ConsoleScanner.h"
#include <iostream>

using namespace std;

ConsoleScanner::ConsoleScanner()
{
}


ConsoleScanner::~ConsoleScanner()
{
}

int ConsoleScanner::readInt(std::string message) {
	int result;
	cout << message;
	cin >> result;
	return result;
}

int ConsoleScanner::readInt() {
	int result;
	cin >> result;
	return result;
}

string ConsoleScanner::readString(std::string message) {
	string result;
	cout << message;
	cin >> result;
	return result;
}

string ConsoleScanner::readString() {
	string result;
	cin >> result;
	return result;
}
