#include "Country.h"
#include "uuid.h"
#include <climits>
#include <utility>
#include "BattleStrategy/Defensive.h"
#include "BattleStrategy/BattleStrategy.h"
#include "BattleStrategy/Diplomacy.h"
#include "BattleStrategy/Offensive.h"
#include "BattleStrategy/Intel.h"
#include "BattleStrategy/Prepare.h"
#include "BattleStrategy/ResearchAndDevelopment.h"
#include "../MapRegions/Map.h"

class Observable;

int Country::sizeOfArmy()  // TODO: Calculate based off of troops
{
  return 0;
}
int Country::prowessInRegion(Region* region) {
  return 0;
}

Country::Country(std::string name) : name(name) {
    double min=0.25, max=0.75;
    //population between 300 000 and 500 000
    population = (int) (uuid::randomInt(0,INT_MAX) % 2000000) + 3000000;
    // All of these values are initialized between 0.25 and 0.75
    economy = (((double) uuid::randomInt(0,INT_MAX) / RAND_MAX) * max-min) + min;
    morale = (((double) uuid::randomInt(0,INT_MAX) / RAND_MAX) * max-min) + min;
    resources = (((double) uuid::randomInt(0,INT_MAX) / RAND_MAX) * max-min) + min;
    research = (((double) uuid::randomInt(0,INT_MAX) / RAND_MAX) * max-min) + min;
    aggressiveness = (((double) uuid::randomInt(0,INT_MAX) / RAND_MAX) * max-min) + min;
    // This value is initialized inbetween 0.05 and 0.1
    goalRating = (((double) uuid::randomInt(0,INT_MAX) / RAND_MAX) * 0.05) + 0.05;
    numSpies = 0;
    strategy = NULL;
    this->weaponFactory = std::shared_ptr<WeaponFlyweightFactory>(new WeaponFlyweightFactory());
    this->generatePersonalityMatrix();
}


// TODO: Destory all owned factories
Country::~Country(){
    if (this->strategy != NULL) {
    }
    if (this->allies != NULL) {
    }
    personalityMatrix.resize(0,0);
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
	0, 0, 0, 0, 0, diploVals[0], 0, diploVals[1], 0, 0, 0, 0, 0, diploVals[2], 0, diploVals[3], 0, 0;  // diplomacy

  delete[] offensiveVals;
  delete[] defensiveVals;
  delete[] developVals;
  delete[] prepVals;
  delete[] intelVals;
  delete[] diploVals;

  this->personalityMatrix = pm;
}

/**
  * @brief Creates a matrix based on the countries avalible resources
  *        This is used to determine the next strategy that the country
  *        will use.
  * @return Eigen::MatrixXd
*/
Eigen::MatrixXd Country::generateValueMatrix() {
  Eigen::MatrixXd valMatrix(18, 1);

  valMatrix <<  ((population==0) ? 0 : numTroops / (0.3 * population)), // Used in calculation of the offensive and defensive value.
		((population == 0) ? 1 : 1 - (numTroops / (0.3 * population))), // Used in calculation of the preperation value.
		((numTroops==0) ? 0 : numVehicles / (numTroops / 10)),
		((numTroops==0) ? 1 : 1 - (numVehicles / (numTroops / 10))),
		economy,
		1 - economy,
		resources,
		1 - resources,
		morale,
		1 - morale,
		((numEnemyRegions == 0) ? 1 :numSpies / (double(numEnemyRegions) / 5)),
		((numEnemyRegions == 0) ? 0 : 1 - (numSpies / (double(numEnemyRegions) / 5))),
		aggressiveness,
		1 - aggressiveness,
		goalRating,
		1 - goalRating,
		research,
		1 - research;

  return valMatrix;
}

double* Country::generateRandomNums(int num) {
  double* vals = new double[num];
  double sum = 0;
  for (int i = 0; i < num; i++) {
    vals[i] = (double)uuid::randomInt(0,INT_MAX) / RAND_MAX;  // array initialisation
    sum += vals[i];
  }

  for (int i = 0; i < num; i++) {
    vals[i] /= sum;
  }

  return vals;
}

void Country::decideStrategy() {
  OccupancyTable* occTable = map->getOccupancyTable();
  numTroops = occTable->getNumTroops(this);
  numVehicles = occTable->getNumVehicles(this);
  numEnemyRegions = (map->getRegionsOwnedBy(this->getAlliance()->isTeamA())).size();

  Eigen::MatrixXd valMatrix = generateValueMatrix();
  Eigen::MatrixXd pm = this->personalityMatrix;
  Eigen::MatrixXd result = pm * valMatrix; // This should return a 1x6 matrix
  // 1. will be the The offensive result
  // 2. will be the Defensive result
  // 3. will be the Development result
  // 4. will be the preperation value
  // 5. will be the intel value
  // 6. will be the diplomacy value.

  //Get max value in result vector
  int maxIndex = 0;
  double maxVal = 0;
  for (int i = 0; i < result.rows(); i++) {
    if (result(i, 0) > maxVal) {
      maxVal = result(i, 0);
      maxIndex = i;
    }
  }

  // valMatrix.resize(0,0);
  // pm.resize(0,0);
  // result.resize(0,0);

  if(this->strategy != NULL) {
    delete this->strategy;
  }

  switch (maxIndex)
  {
      case 0:
	  this->strategy = new Offensive(map);
	  break;
  // case 1:
    // this->strategy = new Defensive(map);
  //   break;
      case 2:
	  this->strategy = new ResearchAndDevelopment(map);
	  break;
      default:
	  this->strategy = new Prepare(map, this);
	  break;
  // case 4:
  //   this->strategy = new Intel(map);
  //   break;
  // case 5:
  //   this->strategy = new Diplomacy(map);
  //   break;
  // default:
  //   this->strategy = new ResearchAndDevelopment(map);
  //   break;
  }
}

void Country::takeTurn() {
  // validateValues();

  decideStrategy();
  this->strategy->doStrategy(this);

  // alertSpyCountries();
}

void Country::validateValues() {

  if(population < 0) { population = 0;}
  if(economy < 0) { economy = 0;}
  if(resources < 0) { resources = 0;}
  if(morale < 0) { morale = 0;}
  if(aggressiveness < 0) { aggressiveness = 0;}
  if(goalRating < 0) { goalRating = 0;}
  if(research < 0) { research = 0;}
  if(numTroops < 0) { numTroops = 0;}
  if(numVehicles < 0) { numVehicles = 0;}
  if(numSpies < 0) { numSpies = 0;}
  if(numEnemyRegions < 0) { numEnemyRegions = 0;}


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


// TODO: Change all of these sets to change actual number of troops and stuff
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


void Country::setCapital(Region * capital) {
    this->capital = capital;
}

void Country::setMap(Map *map) {
    this->map = map;
    OccupancyTable* occTable = map->getOccupancyTable();
    numTroops = occTable->getNumTroops(this);
    numVehicles = occTable->getNumVehicles(this);
    numEnemyRegions = (map->getRegionsOwnedBy(this->getAlliance()->isTeamA())).size();
}
