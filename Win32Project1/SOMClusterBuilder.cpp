#include "SOMClusterBuilder.h"
#include "SOMCluster.h"

SOMClusterBuilder& SOMClusterBuilder::setEpochs(unsigned int epochs) {
	EPOCHS = epochs;
	return *this;
}

SOMClusterBuilder& SOMClusterBuilder::setNeighborhoodFunction(unique_ptr<NeighborhoodFunction> h_p)
{
	h = std::move(h_p);
	return *this;
}

SOMClusterBuilder& SOMClusterBuilder::setWeights(vector<vector<long double>> W) {
	W = W;
	return *this;
}

SOMClusterBuilder& SOMClusterBuilder::setClusters(int COUNT_CLUSTERS_p) {
	COUNT_CLUSTERS = COUNT_CLUSTERS_p;
	return *this;
}

SOMClusterBuilder& SOMClusterBuilder::setDimension(int dimension) {
	DIMENSION = dimension;
	return *this;
}

SOMClusterBuilder& SOMClusterBuilder::setUpdateNeighborhood(bool update_neighborhood) {
	UPDATE_NEIGHBORHOOD = update_neighborhood;
	return *this;
}
	
unique_ptr<SOMCluster> SOMClusterBuilder::build() {
	unique_ptr<SOMCluster> output;
	if (W.size() > 0) {
		output = make_unique<SOMCluster>(EPOCHS, std::move(h), W);
	}
	else {
		output = make_unique<SOMCluster>(EPOCHS, DIMENSION, COUNT_CLUSTERS, std::move(h));
	}
	output->setUpdateNeighborhood(UPDATE_NEIGHBORHOOD);
	return std::move(output);
}
