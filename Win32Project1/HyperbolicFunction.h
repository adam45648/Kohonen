#pragma once
#include "NeighborhoodFunction.h"
#include <math.h>

class HyperbolicFunction : public NeighborhoodFunction
{
public:
	HyperbolicFunction();
	~HyperbolicFunction();
	long double calculate(vector<long double> w1, vector<long double> w2) override;

};

