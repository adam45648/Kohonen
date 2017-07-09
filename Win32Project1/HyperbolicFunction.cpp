#include "HyperbolicFunction.h"



HyperbolicFunction::HyperbolicFunction()
{
}


HyperbolicFunction::~HyperbolicFunction()
{
}

long double HyperbolicFunction::calculate(vector<long double> w1, vector<long double> w2)
{
	long double dist = 0.0;
	for (int i = 0; i < w1.size(); i++) {
		dist += pow(w1[i] - w2[i], 2);
	}
	dist = sqrt(dist);
	return (1L / (1L + dist));
}
