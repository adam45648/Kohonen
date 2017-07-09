#include "SOMCluster.h"

SOMCluster::SOMCluster(const unsigned int EPOCHS_p, const unsigned int DIMENSION_p, const unsigned int COUNT_CLUSTERS_p, unique_ptr<NeighborhoodFunction> h_p) :
	EPOCHS{EPOCHS_p},
	DIMENSION{ DIMENSION_p },
	COUNT_CLUSTERS{COUNT_CLUSTERS_p}
{
	h = move(h_p);
	W = vector<vector<long double>>(COUNT_CLUSTERS, vector<long double>(DIMENSION, 0));
	initRandomWeights();
	UPDATE_NEIGHBORHOOD = true;
	logger.turnOn(true);
}

SOMCluster::SOMCluster(const unsigned int EPOCHS_p, unique_ptr<NeighborhoodFunction> h_p, vector<vector<long double>> W_p):
	EPOCHS{ EPOCHS_p },
	DIMENSION{ W_p.size() },
	COUNT_CLUSTERS{ W_p[0].size() }
{
	h = move(h_p);
	W = W_p;
	UPDATE_NEIGHBORHOOD = true;
	logger.turnOn(true);
}

SOMCluster::~SOMCluster()
{
}

void SOMCluster::setUpdateNeighborhood(bool t)
{
	UPDATE_NEIGHBORHOOD = t;
}

void SOMCluster::initRandomWeights() {
	const double lower_bound = 0;
	const double upper_bound = 1;
	uniform_real_distribution<double> unif(lower_bound, upper_bound);

	random_device rand_dev;          // Use random_device to get a random seed.
	mt19937 rand_engine(rand_dev()); // mt19937 is a good pseudo-random number generator.
	
	for (int i = 0; i < COUNT_CLUSTERS; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			W[i][j] = unif(rand_engine);
			std::cout << W[i][j] << std::endl;
		}
	}
}

vector<vector<long double>> SOMCluster::train(vector<vector<long double>> patterns) {
	unsigned int count_epoch = 1;
	logger.addToLog("Wchodzê do train");
	logger.addToLog("Zainicjalizowane wagi:");
	logger.addVector2DToLog(W);
	logger.addToLog("---------------------------------------------------------");

	while (count_epoch < EPOCHS + 1) {
		logger.addToLog("---------------------------------------------------------");
		logger.addToLog("Epoka: " + count_epoch);
		for (int i = 0; i < patterns.size(); i++) {
			vector<long double> distances(W.size(), 0);

			logger.addToLog("---------------------------------------------------------");
			logger.addToLog("Wzorce: ");
			logger.addVectorToLog(patterns[i]);

			for (int j = 0; j < COUNT_CLUSTERS; j++) {
				distances[j] = distance(W[j], patterns[i]);
				logger.addToLog("Dystansy wag " + to_string(j) + ": " + to_string(distances[j]));
			}
			int small = smallest(distances);

			logger.addToLog("Macierz wag");
			logger.addVector2DToLog(W);
	//		//Update the winner
			for (int j = 0; j < DIMENSION; j++) {
				W[small][j] = W[small][j] + ((1L / (long double)count_epoch)*
					(patterns[i][j] - W[small][j]));
			}

			logger.addToLog("Aktualizacja: " + to_string(small) + " Waga: ");
			logger.addVectorToLog(W[small]);

	//		//Update losers
			if (UPDATE_NEIGHBORHOOD) {
				for (int j = 0; j < patterns.size(); j++) {
					for (int k = 0; k < W.size(); k++) {
						if (k != small) {
							for (int l = 0; l < DIMENSION; l++) {

								long double d = h->calculate(W[k], W[small]);
								long double error = (patterns[j][l] - W[small][l]);

								W[k][l] = W[k][l] + (1L / (long double)count_epoch)*
									d * error;
							}
						}
					}
				}
			}
		}

		count_epoch++;
	}
	logger.addToLog("---------------------------------------------------------");
	logger.addToLog("Wagi koñcowe:");
	logger.addVector2DToLog(W);
	logger.printLog();
	return W;
}

int SOMCluster::test(vector<long double> pattern) {
	vector<long double> distances (COUNT_CLUSTERS);
	for (int i = 0; i < COUNT_CLUSTERS; i++) {
		distances[i] = distance(W[i], pattern);
	}
	return smallest(distances);
}

int SOMCluster::smallest(vector<long double> distances) {
	int output = -1;
	long double minor = LDBL_MAX;
	for (size_t i = 0; i < distances.size(); i++) {
		if (distances[i] < minor) {
			minor = distances[i];
			output = i;
		}
	}
	return output;
}

double SOMCluster::distance(vector<long double> w, vector<long double> point) {
	long double sum = 0.0;
	for (size_t i = 0; i < w.size(); i++) {
		sum += pow(w[i] - point[i], 2);
	}
	return sqrt(sum);
}
