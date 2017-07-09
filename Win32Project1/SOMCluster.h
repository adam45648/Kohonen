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
#include <utility>

using namespace std;

class SOMCluster
{
public:

	SOMCluster(const unsigned int EPOCHS_p, const unsigned int DIMENSION_p, const unsigned int COUNT_CLUSTERS_p, unique_ptr<NeighborhoodFunction> h_p);

	SOMCluster(const unsigned int EPOCHS_p, unique_ptr<NeighborhoodFunction> h, vector<vector<long double>> W);

	~SOMCluster();

	void setUpdateNeighborhood(bool t);

	void initRandomWeights();

	vector<vector<long double>> train(vector<vector<long double>> patterns);

	int test(vector<long double> pattern);

	int smallest(vector<long double> distances);

	double distance(vector<long double> w, vector<long double> point);

private:
	const unsigned int EPOCHS;
	unique_ptr<NeighborhoodFunction> h;
	vector<vector<long double>> W;
	const unsigned int COUNT_CLUSTERS;
	const unsigned int DIMENSION;
	bool UPDATE_NEIGHBORHOOD;
	Logger logger;
};

