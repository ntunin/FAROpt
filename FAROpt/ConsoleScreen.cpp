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


int ConsoleScreen::readInt(string message) {
	return Shared::bundle().scanner()->readInt(message);
}

string ConsoleScreen::readString(string message) {
	return Shared::bundle().scanner()->readString(message);
}


ConsoleScreen::~ConsoleScreen()
{
}
