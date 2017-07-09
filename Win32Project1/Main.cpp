#include "HyperbolicFunction.h"
#include <memory>
#include "SOMClusterBuilder.h"
#include "SOMCluster.h"

int main()
{
	unsigned int epochs = 1;
	unsigned int clusters = 4;
	unsigned int dimensions = 2;
	bool updateNeighborhood = true;
	unique_ptr<NeighborhoodFunction> fun = make_unique<HyperbolicFunction>();
	vector<vector<long double> > weigths = { {0.5, -0.3}, { -0.5,0.8 }, { -0.9,-0.7 }, { -0.2,0.8 } };
	vector<vector<long double> > trainingPatterns = { { -0.54,0.36 },{ 0.16,0.70 },{ -0.80,-0.18 },{ -0.36,-0.52 },{ -0.64,0.46 },{ -0.40,0.34 },{ -0.54,0.36 } };
	vector<vector<long double> > test = { {-0.88, 0.82}, { -0.38,-0.58 }, { 0.48,0.18 }, { 0.68,-0.7 } };

	unique_ptr<SOMCluster> som = SOMClusterBuilder()
										.setClusters(4)
										.setEpochs(10)
										.setDimension(2)
										.setNeighborhoodFunction(std::move(fun))
										.setUpdateNeighborhood(true)
										.setWeights(weigths)
										.build();

	auto weightsTrain = som->train(trainingPatterns);
	Logger logger;
	logger.turnOn(true);
	logger.addVector2DToLog(weightsTrain);
	system("pause");
	return 0;
}