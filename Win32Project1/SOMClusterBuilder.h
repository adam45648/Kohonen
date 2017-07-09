#pragma once
#include "NeighborhoodFunction.h"
#include "SOMCluster.h"
#include <vector>
#include <memory>
#include <utility>

class SOMClusterBuilder
{
public:
	SOMClusterBuilder() = default;
	~SOMClusterBuilder() = default;

	SOMClusterBuilder& setEpochs(unsigned int epochs);

	SOMClusterBuilder& setNeighborhoodFunction(unique_ptr<NeighborhoodFunction> h);

	SOMClusterBuilder& setWeights(vector<vector<long double>> W);

	SOMClusterBuilder& setClusters(int COUNT_CLUSTERS);

	SOMClusterBuilder& setDimension(int dimension);

	SOMClusterBuilder& setUpdateNeighborhood(bool UPDATE_NEIGHBORHOOD);

	unique_ptr<SOMCluster> build();

private:
	int EPOCHS;
	unique_ptr<NeighborhoodFunction> h;
	vector<vector<long double> > W;
	unsigned int COUNT_CLUSTERS;
	unsigned int DIMENSION;
	bool UPDATE_NEIGHBORHOOD;
};
//Test
