#pragma once
#include <string>
#include "NeighborhoodFunction.h"
#include <memory>
#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <math.h>
#include <algorithm>
#include "Logger.h"

using namespace std;

class SOMCluster
{
public:
	SOMCluster(const unsigned int e, unique_ptr<NeighborhoodFunction> n, const int cc, const int d, bool un, string tl);
	~SOMCluster();

	void initRandomWeights();

	vector<vector<long double>> train(vector<vector<long double>> patterns);

	void printArray(vector<long double> printedArray);

	int test(vector<long double> pattern);

	int smallest(vector<long double> distances);

	double distance(vector<long double> w, vector<long double> point);

private:
	const unsigned int EPOCHS;
	unique_ptr<NeighborhoodFunction> h;
	vector<vector<long double>> W;
	const int COUNT_CLUSTERS;
	const int DIMENSION;
	bool UPDATE_NEIGHBORHOOD;
	Logger logger;
};

