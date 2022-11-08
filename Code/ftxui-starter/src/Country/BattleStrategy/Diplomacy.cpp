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
    int temp = 0;
    Logger::log("Do the diplomacy strategy");
    if(myCountry->getPopulation() < enemyCountry->getPopulation()){temp++;}
    if(myCountry->getEconomy() < enemyCountry->getEconomy()){temp++;}
    if(myCountry->getMorale() < enemyCountry->getEconomy()){temp++;}
    if(myCountry->getResources() < enemyCountry->getResources()){temp++;}
    if(myCountry->getResearch() < enemyCountry->getResources()){temp++;}

    if(temp = 3){
        proposeTreaty();
    }
    else if(temp > 3){
        surrender();
    }
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
    Logger::log(myCountry->getName() + " proposed a treaty with " + enemyCountry->getName());
}

/**
 * @fn void surrender()
 * @brief Surrender to another country.
 * 
 */
void Diplomacy::surrender(){
    Logger::log(myCountry->getName() + " surrended to " + enemyCountry->getName());
}
