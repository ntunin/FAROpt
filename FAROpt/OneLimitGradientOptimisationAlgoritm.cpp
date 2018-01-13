#include "stdafx.h"
#include "OneLimitGradientOptimisationAlgoritm.h"

using namespace std;

OneLimitGradientOptimisationAlgoritm::OneLimitGradientOptimisationAlgoritm(OneLimitOptimisationEnvirounment *envirounment) {
	solveDirectivityOptimisationTask(envirounment);
}

void OneLimitGradientOptimisationAlgoritm::solveVariationalOptimisationTask() {
	this->solve();
}

OneLimitGradientOptimisationAlgoritm::~OneLimitGradientOptimisationAlgoritm()
{
}
