#include "Intel.h"

/**
 * @file Intel.cpp
 * @brief Construct a new Diplomacy Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Intel(Map* map)
 * @brief The constructor for the Intel class
 * 
 * @param map allows access to the map
 */
Intel::Intel(Map* map) : BattleStrategy(map){}

Intel::Intel() : BattleStrategy(NULL) {  }

void Intel::doStrategy(Country* country){
    int enemyToSPyOnIndex = uuid::randomInt(0, country->allies->getEnemyAlliance()->numCountries() - 1);
    Country* enemyToSpyOn = country->allies->getEnemyAlliance()->getIthCountry(enemyToSPyOnIndex);

    std::vector<std::pair<Country*, double>>* countriesBeingSpiedOn = country->getCountriesBeingSpiedOn();
    bool alreadyBeingSpiedOn = false;
    for(int i = 0; i < countriesBeingSpiedOn->size() && !alreadyBeingSpiedOn; i++){
        if((*countriesBeingSpiedOn)[i].first == enemyToSpyOn){
            alreadyBeingSpiedOn = true;
        }
    }

    if(!alreadyBeingSpiedOn){
        country->spyOnCountry(enemyToSpyOn);
        country->setNumSpies(country->getNumSpies() + 1);
        countriesBeingSpiedOn->push_back(std::pair<Country*, double>(enemyToSpyOn, 0));
        Logger::log(country->name + " is now spying on :" + enemyToSpyOn->name + "\n");
        // country->spyOnCountry(enemyToSpyOn);
        // countriesBeingSpiedOn->push_back(std::pair<Country*, double>(enemyToSpyOn, 0));
        // Logger::log(country->name + " is now spying on :" + enemyToSpyOn->name);
    } 
}

/**
 * @fn void setMyCountry(Country* myCountry)
 * @brief a setter for the myCountry variable.
 * 
 * @param myCountry holds a reference to the country which called the algorithm.
 */
void Intel::setMyCountry(Country* myCountry){
    this->myCountry = myCountry;
}

/**
 * @fn void setEnemyCountry(Country* enemyCountry)
 * @brief a setter for the enemyCountry variable.
 * 
 * @param enemyCountry holds a reference an enemy country of the country which called the algorithm.
 */
void Intel::setEnemyCountry(Country* enemyCountry){
    this->enemyCountry = enemyCountry;

}