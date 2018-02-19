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


ProcessManager * Shared::processManager() {
	return this->processManagerInstance;
}

void  Shared::processManager(ProcessManager *manager) {
	this->processManagerInstance = manager;
}


CacheManager *Shared::cacheManager() {
	return this->cahceManagerInstance;
}

void Shared::cacheManager(CacheManager *manager) {
	this->cahceManagerInstance = manager;
}


TaskManager *Shared::taskManager(){
	return this->taskManagerInstance;
}

void Shared::taskManager(TaskManager *manager) {
	this->taskManagerInstance = manager;
}


RandomGenerator *Shared::randomGenerator() {
	return this->generatorInstance;
}
void Shared::randomGenerator(RandomGenerator *generatorInstance) {
	this->generatorInstance = generatorInstance;
}
