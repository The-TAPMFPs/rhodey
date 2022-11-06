#include "Country.h"

unsigned int Country::sizeOfArmy()  // TODO: Calculate based off of troops
{
  return 0;
}
unsigned int Country::prowessInRegion(Region* region) {
  return 0;
}

Country::Country(std::string name) : name(name) {
  int min = 0.25, max = 0.75;
  srand((unsigned)time(NULL));
  population = (int)(rand() % 500000 - 300000 + 1) +
               3000000;  // population between 300 000 and 500 000
  economy = min + (double)(rand() / RAND_MAX) * (max - min);
  morale = min + (double)(rand() / RAND_MAX) * (max - min);
  resources = min + (double)(rand() / RAND_MAX) * (max - min);
  research = min + (double)(rand() / RAND_MAX) * (max - min);
  aggressiveness = min + (double)(rand() / RAND_MAX) * (max - min);
  goalRating = 0;
  numSpies = 0;
  numTroops = 0;
  numVehicles = 0;
  numEnemyRegions = 0;
  generatePersonalityMatrix();
}

std::string Country::getName() {
  return this->name;
}

void Country::generatePersonalityMatrix() {
  Eigen::MatrixXd pm(6, 18);
  double* offensiveVals = generateRandomNums(4);
  double* defensiveVals = generateRandomNums(4);
  double* developVals = generateRandomNums(3);
  double* prepVals = generateRandomNums(3);
  double* intelVals = generateRandomNums(1);
  double* diploVals = generateRandomNums(4);

  pm << offensiveVals[0], 0, offensiveVals[1], 0, 0, 0, 0, 0, 0,
      offensiveVals[2], 0, 0, offensiveVals[3], 0, 0, 0, 0, 0,  // offensive
      defensiveVals[0], 0, defensiveVals[1], 0, 0, 0, 0, 0, 0, defensiveVals[2],
      0, 0, defensiveVals[3], 0, 0, 0, 0, 0,  // defensive
      0, 0, 0, 0, 0, developVals[0], 0, developVals[1], 0, 0, 0, 0, 0, 0, 0, 0,
      0, developVals[2],  // development
      0, prepVals[0], 0, prepVals[1], prepVals[2], 0, 0, prepVals[3], 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0,  // preparation
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, intelVals[0], 0, 0, 0, 0, 0, 0,  // intel
      0, 0, 0, 0, 0, diploVals[0], 0, diploVals[1], 0, 0, 0, 0, 0, diploVals[2],
      diploVals[3], 0, 0, 0;  // diplomacy

  this->personalityMatrix = pm;
}

Eigen::MatrixXd Country::generateValueMatrix() {
  Eigen::MatrixXd valMatrix(18, 1);
  valMatrix << numTroops / (0.3 * population),
      1 - (numTroops / (0.3 * population)), numVehicles / (numTroops / 10),
      1 - (numVehicles / (numTroops / 10)), economy, 1 - economy, resources,
      1 - resources, morale, 1 - morale, numSpies / (numEnemyRegions / 5),
      1 - (numSpies / (numEnemyRegions / 5)), aggressiveness,
      1 - aggressiveness, goalRating, 1 - goalRating, research, 1 - research;

  return valMatrix;
}

double* Country::generateRandomNums(int num) {
  srand((unsigned)time(NULL));

  double* vals = new double[num];
  double sum = 0;
  for (int i = 0; i < num; i++) {
    vals[i] = (double)rand() / RAND_MAX;  // array initialisation
    sum += vals[i];
  }

  for (int i = 0; i < num; i++) {
    vals[i] /= sum;
  }

  return vals;
}

void Country::setStrategy(BattleStrategy* strategy) {
  this->strategy = strategy;
}

int Country::nextStrategy() {
  Eigen::MatrixXd valMatrix = generateValueMatrix();
  Eigen::MatrixXd pm = this->personalityMatrix;
  Eigen::MatrixXd result = pm * valMatrix;
  int maxIndex = 0;
  double maxVal = 0;
  for (int i = 0; i < result.rows(); i++) {
    if (result(i, 0) > maxVal) {
      maxVal = result(i, 0);
      maxIndex = i;
    }
  }
  return maxIndex;
}

void Country::takeTurn() {
  int nextStrat = nextStrategy();

  switch (nextStrat) {
    case 0:

      // loop through regions, check if there is an enemy region in which we
      // have a 90% troop ratio to enemies if so, attack else move troops to
      // region with least enemy troops and easy to get there

      break;
    case 1:
      // if there is a non contesting region, move those troops to a contesting
      // region if no contesting region then recruit this->strategy = new
      // Defensive();
      break;
    case 2:
      // develop the lowest stat between economy, resources and research
      // this->strategy = new ResearchAndDevelopment();
      break;
    case 3:
      // take action of lowest between trrop and vehicle count
      // this->strategy = new PreparationStrategy();
      break;
    case 4:
      // create spy on an enemy region with most enemy or friendly troops
      // this->strategy = new IntelligenceStrategy();
      break;
    case 5:
      // if goal rating is high and aggressivness is low then propose treaty,
      // else surrender() this->strategy = new DiplomacyStrategy();
      break;
    default:
      // this->strategy = new Offensive(red);
      break;
  }
}

std::vector<std::string> Country::getFormattedStats() {
  return std::vector<std::string>{
      "Population: " + std::to_string(population),
      "Economy: " + std::to_string(economy),
      "Morale: " + std::to_string(morale),
      "Resources: " + std::to_string(resources),
      "Research: " + std::to_string(research),
      "Aggressiveness: " + std::to_string(aggressiveness),
      "Goal Rating: " + std::to_string(goalRating),
      "Number of Spies: " + std::to_string(numSpies)};
}