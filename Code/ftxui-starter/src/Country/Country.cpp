#include "Country.h"
#include "BattleStrategy/Defensive.h"
#include "BattleStrategy/BattleStrategy.h"
#include "BattleStrategy/Diplomacy.h"
#include "BattleStrategy/Offensive.h"
#include "BattleStrategy/Intel.h"
#include "BattleStrategy/Prepare.h"
#include "BattleStrategy/ResearchAndDevelopment.h"

unsigned int Country::sizeOfArmy()  // TODO: Calculate based off of troops
{
  return 0;
}
unsigned int Country::prowessInRegion(Region* region) {
  return 0;
}

Country::Country(std::string name) : name(name) {
    double min=0.25, max=0.75;
    srand((unsigned)time(NULL));
    population = (int) (rand() % 500000-300000+1) + 3000000; //population between 300 000 and 500 000
    economy = (((double) rand() / RAND_MAX) * max-min) + min;
    morale = (((double) rand() / RAND_MAX) * max-min) + min;
    resources = (((double) rand() / RAND_MAX) * max-min) + min;
    research = (((double) rand() / RAND_MAX) * max-min) + min;
    aggressiveness = (((double) rand() / RAND_MAX) * max-min) + min;
    goalRating = 0;
    numSpies = 0;
    numTroops = 0;
    numVehicles = 0;
    numEnemyRegions = 0;
    generatePersonalityMatrix();
}

Country::~Country(){
    if (this->strategy != NULL) {
	//delete this->strategy;
    }
    personalityMatrix.resize(0,0);
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

  pm << offensiveVals[0], 0, offensiveVals[1], 0, 0, 0, 0, 0, 0, offensiveVals[2], 0, 0, offensiveVals[3], 0, 0, 0, 0, 0,  // offensive
      defensiveVals[0], 0, defensiveVals[1], 0, 0, 0, 0, 0, 0, defensiveVals[2], 0, 0, defensiveVals[3], 0, 0, 0, 0, 0,  // defensive
      0, 0, 0, 0, 0, developVals[0], 0, developVals[1], 0, 0, 0, 0, 0, 0, 0, 0, 0, developVals[2],  // development
      0, prepVals[0], 0, prepVals[1], prepVals[2], 0, 0, prepVals[3], 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // preparation
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, intelVals[0], 0, 0, 0, 0, 0, 0,  // intel
      0, 0, 0, 0, 0, diploVals[0], 0, diploVals[1], 0, 0, 0, 0, 0, diploVals[2], diploVals[3], 0, 0, 0;  // diplomacy

  delete[] offensiveVals;
  delete[] defensiveVals;
  delete[] developVals;
  delete[] prepVals;
  delete[] intelVals;
  delete[] diploVals;

  this->personalityMatrix = pm;
}

Eigen::MatrixXd Country::generateValueMatrix() {
  Eigen::MatrixXd valMatrix(18, 1);
  valMatrix << ((population==0) ? 0 : numTroops / (0.3 * population)),
    ((numTroops == 0) ? 1 : 1 - (numTroops / (0.3 * population))),
      ((numTroops==0) ? 0 : numVehicles / (numTroops / 10)),
      ((numTroops==0) ? 1 : 1 - (numVehicles / (numTroops / 10))),
      economy,
      1 - economy,
      resources,
      1 - resources,
      morale,
      1 - morale,
      ((numEnemyRegions == 0) ? 1 :numSpies / (numEnemyRegions / 5)),
      ((numEnemyRegions == 0) ? 0 : 1 - (numSpies / (numEnemyRegions / 5))),
      aggressiveness,
      1 - aggressiveness,
      goalRating,
      1 - goalRating,
      research,
      1 - research;

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

void Country::decideStrategy() {
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

  valMatrix.resize(0,0);
  pm.resize(0,0);
  result.resize(0,0);

  if(this->strategy != NULL) {
    delete this->strategy;
  }
  switch (maxIndex)
  {
  case 0:
    this->strategy = new Offensive();
    break;
  case 1:
    this->strategy = new Defensive();
    break;
  case 2:
    this->strategy = new ResearchAndDevelopment();
    break;
  case 3:
    this->strategy = new Prepare();
    break;
  case 4:
    this->strategy = new Intel();
    break;
  case 5:
    this->strategy = new Diplomacy();
    break;
  default:
    this->strategy = new ResearchAndDevelopment();
    break;
  }
}

void Country::takeTurn() {
  decideStrategy();
  this->strategy->doStrategy(this);

  alertSpyCountries();
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

std::vector<std::pair<Country*, double>>* Country::getCountriesBeingSpiedOn() {
  return &countriesBeingSpiedOn;
}

void Country::setPopulation(int population) {
  this->population = population;
}

void Country::setEconomy(double economy) {
  this->economy = economy;
}

void Country::setMorale(double morale) {
  this->morale = morale;
}

void Country::setResources(double resources) {
  this->resources = resources;
}

void Country::setResearch(double research) {
  this->research = research;
}

void Country::setAggressiveness(double aggressiveness) {
  this->aggressiveness = aggressiveness;
}

void Country::setGoalRating(double goalRating) {
  this->goalRating = goalRating;
}

void Country::setNumSpies(int numSpies) {
  this->numSpies = numSpies;
}

void Country::setNumTroops(int numTroops) {
  this->numTroops = numTroops;
}

void Country::setNumVehicles(int numVehicles) {
  this->numVehicles = numVehicles;
}

void Country::setNumEnemyRegions(int numEnemyRegions) {
  this->numEnemyRegions = numEnemyRegions;
}

int Country::getPopulation() {
  return this->population;
}

double Country::getEconomy() {
  return this->economy;
}

double Country::getMorale() {
  return this->morale;
}

double Country::getResources() {
  return this->resources;
}

double Country::getResearch() {
  return this->research;
}

double Country::getAggressiveness() {
  return this->aggressiveness;
}

double Country::getGoalRating() {
  return this->goalRating;
}

int Country::getNumSpies() {
  return this->numSpies;
}

int Country::getNumTroops() {
  return this->numTroops;
}

int Country::getNumVehicles() {
  return this->numVehicles;
}

int Country::getNumEnemyRegions() {
  return this->numEnemyRegions;
}

