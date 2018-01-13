#pragma once
#include "OptimisationAlgoritm.h"

class GradientAlgoritm: public OptimisationAlgoritm
{

public:
	GradientAlgoritm();
	void solve();
	~GradientAlgoritm();
};

