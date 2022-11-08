#include "Diplomacy.h"

/**
 * @file Diplomacy.cpp
 * @brief Construct a new Diplomacy Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Diplomacy(Map* map)
 * @brief The constructor for the Diplomacy class
 * 
 * @param map allows access to the map
 */
Diplomacy::Diplomacy(Map* map) : BattleStrategy(map){}

/**
 * @fn void doStrategy(Country* country)
 * @brief Determines whether a country should propose a treaty or surrender based on there 
 population, economy, morale, resources, research.
 * 
 * @param country 
 */

void Diplomacy::doStrategy(Country* country){
    setEnemyCountry((map->getTeamsRegionWithEnemyRatio(country->getAlliance()->isTeamA(), true, true))->getPossessor());
    setMyCountry(country);

    int score = 0;
    if(myCountry->getNumTroops() <= enemyCountry->getNumTroops()){score++;}
    if(myCountry->getEconomy() <= enemyCountry->getEconomy()){score++;}
    if(myCountry->getMorale() <= enemyCountry->getMorale()){score++;}
    if(myCountry->getResources() <= enemyCountry->getResources()){score++;}
    if(myCountry->getNumVehicles() <= enemyCountry->getNumVehicles()){score++;}
    if(myCountry->getNumSpies() <= enemyCountry->getNumSpies()){score++;}
    if(myCountry->getPopulation() <= enemyCountry->getPopulation()){score++;}
    
    if(score <= 4){
        proposeTreaty();
    } else {
        surrender();
    }
    srand((unsigned)time(NULL));
    double change = (((double) rand() / RAND_MAX) * 0.05-0.01) + 0.01;
    country->setAggressiveness(country->getAggressiveness() - change);


}

/**
 * @fn void setMyCountry(Country* myCountry)
 * @brief a setter for the myCountry variable.
 * 
 * @param myCountry holds a reference to the country which called the algorithm.
 */
void Diplomacy::setMyCountry(Country* myCountry){
    this->myCountry = myCountry;
}

/**
 * @fn void setEnemyCountry(Country* enemyCountry)
 * @brief a setter for the enemyCountry variable.
 * 
 * @param enemyCountry holds a reference an enemy country of the country which called the algorithm.
 */
void Diplomacy::setEnemyCountry(Country* enemyCountry){
    this->enemyCountry = enemyCountry;
}

/**
 * @fn void proposeTreaty()
 * @brief Proposes a treaty to an enemy country.
 * 
 */
void Diplomacy::proposeTreaty(){
    Logger::log(myCountry->getName() + " proposed a treaty with " + enemyCountry->getName() + "\n");

    int score = 0;
    if(myCountry->getNumTroops()/enemyCountry->getNumTroops() >0.95){score++;}
    if(myCountry->getEconomy()/enemyCountry->getEconomy() >0.95){score++;}
    if(myCountry->getMorale()/enemyCountry->getMorale() >0.95){score++;}
    if(myCountry->getResources()/enemyCountry->getResources() >0.95){score++;}
    if(myCountry->getNumVehicles()/enemyCountry->getNumVehicles() >0.95){score++;}
    if(myCountry->getNumSpies()/enemyCountry->getNumSpies() >0.95){score++;}
    if(myCountry->getPopulation()/enemyCountry->getPopulation() >0.95){score++;}

    if(score >= 5){
        Logger::log(enemyCountry->getName() + " has accepted " + myCountry->getName() + "'s treaty" + "\n");
    } else {
        Logger::log(enemyCountry->getName() + " has rejected " + myCountry->getName() + "'s treaty" + "\n");

    }
    //Have a treaty function in the country
}

/**
 * @fn void surrender()
 * @brief Surrender to another country.
 * 
 */
void Diplomacy::surrender(){
    Logger::log(myCountry->getName() + " has surrendered to " + enemyCountry->getName() + "\n");
    //end war
    //Have a surrender function in the country
}
