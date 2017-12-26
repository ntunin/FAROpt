#include "stdafx.h"
#include "Shared.h"


Shared::Shared()
{
}


Shared::~Shared()
{
}


Log* Shared::log() {
	return this->logInstance;
}

void Shared::log(Log *log) {
	this->logInstance = log;
}

Scanner *Shared::scanner() {
	return this->scannerInstance;
}

void Shared::scanner(Scanner *scanner) {
	this->scannerInstance = scanner;
}
