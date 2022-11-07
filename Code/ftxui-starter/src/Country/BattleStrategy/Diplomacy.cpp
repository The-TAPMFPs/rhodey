#include "Diplomacy.h"

/**
 * @file Diplomacy.cpp
 * @brief Construct a new Diplomacy Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Diplomacy()
 * @brief The constructor for the Diplomacy class
 */
Diplomacy::Diplomacy(){
}

/**
 * @fn void warAlgorithm(int dip)
 * @brief Decides on which strategy algorithm to use based on an enum.
 * 
 * @param dip An int that is converted to an enum and switched to decide on the strategy.
 */
void Diplomacy::warAlgorithm(int dip){
    this->dip =(_dip) dip;

    switch(dip){
        case suDip:
            surrender();
            break;
        case ptDip:
            proposeTreaty();
            break;
    }
    return;
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
    std::string temp; /**<A string to hold the message that a treaty was proposed*/
    temp = myCountry->getName() + " proposed a treaty with " + enemyCountry->getName();
    Logger::log(temp);
    //Have a treaty function in the country
}

/**
 * @fn void surrender()
 * @brief Surrender to another country.
 * 
 */
void Diplomacy::surrender(){
    std::string temp; /**<A string to hold the message that a country surrendered*/
    temp = myCountry->getName() + " surrended to " + enemyCountry->getName();
    Logger::log(temp);
    //Have a surrender function in the country
}
