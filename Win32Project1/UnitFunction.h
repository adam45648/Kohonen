#pragma once
#include "NeighborhoodFunction.h"

class UnitFunction : public NeighborhoodFunction
{
public:
	UnitFunction();
	~UnitFunction();
	long double calculate(vector<long double> w1, vector<long double> w2) override;
};

