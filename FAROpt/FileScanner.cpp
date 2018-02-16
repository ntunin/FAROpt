#include "stdafx.h"
#include "FileScanner.h"

using namespace std;

FileScanner::FileScanner(string path) {
	file = new ifstream();
	file->open(path, std::ifstream::in);
}


FileScanner::~FileScanner() {
	file->close();
}

int FileScanner::readInt(std::string message) {
	int result;
	Shared::bundle().log()->print(message);
	(*file) >> result;
	Shared::bundle().log()->print(result);
	Shared::bundle().log()->print("\n");
	return result;
}

int FileScanner::readInt() {
	int result;
	(*file) >> result;
	return result;
}

double FileScanner::readDouble(std::string message) {
	double result;
	Shared::bundle().log()->print(message);
	(*file) >> result;
	Shared::bundle().log()->print(result);
	Shared::bundle().log()->print("\n");
	return result;
}

double FileScanner::readDouble() {
	double result;
	(*file) >> result;
	return result;
}


string FileScanner::readString(std::string message) {
	string result;
	Shared::bundle().log()->print(message);
	(*file) >> result;
	Shared::bundle().log()->print(result);
	Shared::bundle().log()->print("\n");
	return result;
}

string FileScanner::readString() {
	string result;
	(*file) >> result;
	return result;
}


bool FileScanner::readBool() {
	std::string answer;
	(*file) >> answer;
	while (true) {
		switch (answer[0])	{
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			break;
		}
		(*file) >> answer;
	}
}

bool FileScanner::readBool(string message) {
	std::string answer;
	Shared::bundle().log()->print(message);
	Shared::bundle().log()->print(" (y / n): >");
	(*file) >> answer;
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
		(*file) >> answer;
	}
}
