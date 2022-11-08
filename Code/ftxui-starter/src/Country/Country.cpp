#include "Country.h"
/**
 * \file Country.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
/**
 * \fn unsigned int Country::sizeOfArmy()
 * \brief calculate the size of the army 
 * \return return the calculated size of the army 
*/
unsigned int Country::sizeOfArmy()  // TODO: Calculate based off of troops
{
  return 0;
}
/**
 * \fn unsigned int Country::prowessInRegion(Region* region)
 * \brief 
*/
unsigned int Country::prowessInRegion(Region* region) {//chris pls do the prowessInRegion func doxygen 
  return 0;
}
/**
 * \fn Country::Country(std::string name)
 * \brief constructor for the Country class which creates new Countries 
 * \param name the name of a newly created country 
*/
Country::Country(std::string name) : name(name) {
    double min=0.25, max=0.75;/**minimum and maximum allowed values (upper and lower bounds)*/
    srand((unsigned)time(NULL));
    population = (int) (rand() % 500000-300000+1) + 3000000;/**the population which is generated is between 300k and 500k*/
    economy = (((double) rand() / RAND_MAX) * max-min) + min;/**the economy(money) a country has is generated in this way */
    morale = (((double) rand() / RAND_MAX) * max-min) + min;/**the variable that stores the morale of a country */
    resources = (((double) rand() / RAND_MAX) * max-min) + min;/**the variable that keeps track of the resources of a country*/
    research = (((double) rand() / RAND_MAX) * max-min) + min;/**variable that stores the amount of research a country has done */
    aggressiveness = (((double) rand() / RAND_MAX) * max-min) + min;/**variable that stores the amount of aggression a country has */
    goalRating = 0;/**goal rating variable that is initialized to 0*/
    numSpies = 0;/**number of spies variable that is initialized to 0*/
    numTroops = 0;/**number of troops variable that is initialized to 0*/
    numVehicles = 0;/**number of vehicles varibale that is initialized to 0*/
    numEnemyRegions = 0;/**number of enemy regions that is initially initialized to 0*/
    generatePersonalityMatrix();

    strats[0] = new Offensive();
    strats[1] = new Defensive();
    strats[2] = new ResearchAndDevelopment();
    strats[3] = new Prepare();
    strats[4] = new Diplomacy();
}
/**
 * \fn Country::~Country()
 * \brief the Country destructor
*/
Country::~Country(){
    for (int count = 0; count < 5; count++) {
	delete strats[count];
    }
}
/**
 * \fn string Country::getName()
 * \brief the function that gets a countries name 
 * \return the function returns the country name 
*/
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

  delete offensiveVals;
  delete defensiveVals;
  delete developVals;
  delete prepVals;
  delete intelVals;
  delete diploVals;

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
    {
      strats[2]->setFriendlyCountry(this);
      if(this->research < this->resources && this->research < this->economy) {
        strats[2]->warAlgorithm(3);
      }
      else if (this->economy < this->resources && this->economy < this->research) {
        strats[2]->warAlgorithm(2);
      }
      else {
        strats[2]->warAlgorithm(1);
      }
      // develop the lowest stat between economy, resources and research
      // this->strategy = new ResearchAndDevelopment();
      break;
    }
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
/**
 * \fn void Country::setPopulation(int population)
 * \brief sets the populaton of a country
 * @param population is the population we want the country to be set to 
*/
void Country::setPopulation(int population) {
  this->population = population;
}
/**
 * \fn void Country::setEconomy(double economy)
 * \brief sets the economy(wealth) of a country
 * @param economy is the ecnonomy(wealth) we want the country to be set to 
*/
void Country::setEconomy(double economy) {
  this->economy = economy;
}
/**
 * \fn void Country::setMorale(double morale)
 * \brief sets the morale of a country
 * @param morale is the morale we want the country to be set to 
*/
void Country::setMorale(double morale) {
  this->morale = morale;
}
/**
 * \fn void Country::setResources(double resources)
 * \brief sets the resources of a country
 * @param resources is the resources we want the country to be set to 
*/
void Country::setResources(double resources) {
  this->resources = resources;
}
/**
 * \fn void Country::setResearch(double Research)
 * \brief sets the Research of a country
 * @param Research is the amount of Research we want the country to be set to 
*/
void Country::setResearch(double research) {
  this->research = research;
}
/**
 * \fn void Country::setAggressiveness(double aggressiveness)
 * \brief sets the aggressiveness of a country
 * @param aggressiveness is the amount of aggressiveness we want the country to be set to 
*/
void Country::setAggressiveness(double aggressiveness) {
  this->aggressiveness = aggressiveness;
}
/**
 * \fn void Country::setGoalRating(double goalRating)
 * \brief sets the Goalrating of a country
 * @param goalRating is the amount of goalRating we want the country to be set to 
*/
void Country::setGoalRating(double goalRating) {
  this->goalRating = goalRating;
}
/**
 * \fn void Country::setNumSpies(int numSpies)
 * \brief sets the number of spies of a country
 * @param numSpies is the amount of spies we want the country to have 
*/
void Country::setNumSpies(int numSpies) {
  this->numSpies = numSpies;
}
/**
 * \fn void Country::setNumTroops(int numTroops)
 * \brief sets the number of Troops of a country
 * @param numTroops is the amount of Troops we want the country to have 
*/
void Country::setNumTroops(int numTroops) {
  this->numTroops = numTroops;
}
/**
 * \fn void Country::setNumVehicles(int numVehilces)
 * \brief sets the number of Vehicles of a country
 * @param numVehicles is the amount of vehicles we want the country to have 
*/
void Country::setNumVehicles(int numVehicles) {
  this->numVehicles = numVehicles;
}
/**
 * \fn void Country::setNumEnemyRegions(int numEnemyRegions)
 * \brief sets the number of EnemyRegions of a country
 * @param numEnemyRegions is the amount of EnemyRegions we want the country to have 
*/
void Country::setNumEnemyRegions(int numEnemyRegions) {
  this->numEnemyRegions = numEnemyRegions;
}
/**
 * \fn int Country::getPopulation()
 * \brief the function that fetches the population of a country 
 * \return the function returns the population of a country 
*/
int Country::getPopulation() {
  return this->population;
}
/**
 * \fn int Country::getEconomy()
 * \brief the function that fetches the Economy of a country 
 * \return the function returns the Economy of a country 
*/
double Country::getEconomy() {
  return this->economy;
}

/**
 * \fn int Country::getMorale()
 * \brief the function that fetches the morale of a country 
 * \return the function returns the morale of a country 
*/
double Country::getMorale() {
  return this->morale;
}
/**
 * \fn int Country::getResources()
 * \brief the function that fetches the Resources of a country 
 * \return the function returns the Resources of a country 
*/
double Country::getResources() {
  return this->resources;
}
/**
 * \fn int Country::getResearch()
 * \brief the function that fetches the Research of a country 
 * \return the function returns the Research of a country 
*/
double Country::getResearch() {
  return this->research;
}
/**
 * \fn int Country::getAggressiveness()
 * \brief the function that fetches the aggressiveness of a country 
 * \return the function returns the aggressiveness of a country 
*/
double Country::getAggressiveness() {
  return this->aggressiveness;
}
/**
 * \fn int Country::getGoalRating()
 * \brief the function that fetches the GoalRating of a country 
 * \return the function returns the GoalRating of a country 
*/
double Country::getGoalRating() {
  return this->goalRating;
}
/**
 * \fn int Country::getNumSpies()
 * \brief the function that fetches the number of spies of a country 
 * \return the function returns the number of spies of a country 
*/
int Country::getNumSpies() {
  return this->numSpies;
}
/**
 * \fn int Country::getNumTroops()
 * \brief the function that fetches the number of troops  of a country 
 * \return the function returns the number of troops of a country 
*/
int Country::getNumTroops() {
  return this->numTroops;
}
/**
 * \fn int Country::getNumVehicles()
 * \brief the function that fetches the number of vehicles of a country 
 * \return the function returns the number of vehicles of a country 
*/
int Country::getNumVehicles() {
  return this->numVehicles;
}
/**
 * \fn int Country::getNumEnemyRegions()
 * \brief the function that fetches the number of enemy regions of a country 
 * \return the function returns the number of enemy rehions of a country 
*/
int Country::getNumEnemyRegions() {
  return this->numEnemyRegions;
}



