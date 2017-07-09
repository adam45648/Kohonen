#pragma once
#include <vector>

using namespace std;

class NeighborhoodFunction
{
public:
	virtual long double calculate(vector<long double> w1, vector<long double> w2) = 0;
	virtual ~NeighborhoodFunction() = default;
};

