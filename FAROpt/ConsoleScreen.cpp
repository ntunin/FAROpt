#include "stdafx.h"
#include "ConsoleScreen.h"

using namespace std;

ConsoleScreen::ConsoleScreen()
{
}

void ConsoleScreen::reset() {
	Shared::bundle().log()->reset();
}

void ConsoleScreen::print(string message) {
	Shared::bundle().log()->print(message);
}

void ConsoleScreen::print(const char *message) {
	Shared::bundle().log()->print(message);
}

void ConsoleScreen::print(ComplexVector *v) {
	Shared::bundle().log()->print(*v);
}

void ConsoleScreen::print(double d) {
	Shared::bundle().log()->print(d);
}


void ConsoleScreen::print(int size, double *v) {
	for (int i = 0; i < size; i++) {
		Shared::bundle().log()->print(v[i]);
		Shared::bundle().log()->print(" ");
	}
}

void ConsoleScreen::print(int size, double **m) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Shared::bundle().log()->print(m[i][j], 8);
			Shared::bundle().log()->print(" ");
		}
		Shared::bundle().log()->print("\n");
	}
}


int ConsoleScreen::readInt(string message) {
	return Shared::bundle().scanner()->readInt(message);
}

string ConsoleScreen::readString(string message) {
	return Shared::bundle().scanner()->readString(message);
}


ConsoleScreen::~ConsoleScreen()
{
}
