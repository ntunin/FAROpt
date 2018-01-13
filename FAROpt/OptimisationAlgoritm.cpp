#include "stdafx.h"
#include "OptimisationAlgoritm.h"


OptimisationAlgoritm::OptimisationAlgoritm()
{
}

void OptimisationAlgoritm::setSize(int size) {
	this->size = size;
}

int OptimisationAlgoritm::getSize() {
	return this->size;
}

bool OptimisationAlgoritm::isMaximisational() {
	return this->maximisation;
}

void OptimisationAlgoritm::makeMaximisational() {
	this->maximisation = true;
}


void OptimisationAlgoritm::setInitial(double *x) {
	this->x = x;
}


double *OptimisationAlgoritm::getCurrentSolution() {
	return this->x;
}


OptimisationAlgoritm::~OptimisationAlgoritm()
{
}
