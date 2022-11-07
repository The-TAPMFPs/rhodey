#include "ResearchAndDevelopment.h"

/**
 * @file Defensive.cpp
 * @brief Construct a new ResearchAndDevelopment Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn ResearchAndDevelopment(Map* map)
 * @brief The constructor for the ResearchAndDevelopment class
 * 
 * @param map allows access to the map
 */
ResearchAndDevelopment::ResearchAndDevelopment(Map* map) : BattleStrategy(map){}


void ResearchAndDevelopment::doStrategy(Country* country){
    // develop the lowest stat between economy, resources and research
    friendlyCountry = country;
    if(country->getResearch() < country->getResources() && country->getResearch() < country->getEconomy()) {
        research();
    }
    else if (country->getEconomy() < country->getResources() && country->getEconomy() < country->getResearch()) {
        developEconomy();
    }
    else {
        developResources();
    }
}

/**
 * @fn void developResources()
 * @brief Researches resource development and improves it for a country.
 * 
 */
void ResearchAndDevelopment::developResources(){
    srand((unsigned)time(NULL));
    double change = (((double) rand() / RAND_MAX) * 0.10-0.01) + 0.01; 
    this->friendlyCountry->setResources(this->friendlyCountry->getResources() + change);
    Logger::log("Resources increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName() + "\n");
}

/**
 * @fn void developEconomy()
 * @brief Researches the ecoonomy and improves it for a country.
 * 
 */
void ResearchAndDevelopment::developEconomy(){
    srand((unsigned)time(NULL));
    double change = (((double) rand() / RAND_MAX) * 0.10-0.01) + 0.01;
    this->friendlyCountry->setEconomy(this->friendlyCountry->getEconomy() + change);
    Logger::log("Economy increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName() + "\n");
}

/**
 * @fn void research()
 * @brief Improves the general research of a country, which affects the strength of the army.
 * 
 */
void ResearchAndDevelopment::research(){
    srand((unsigned)time(NULL));
    double change = (((double) rand() / RAND_MAX) * 0.10-0.01) + 0.01;
    this->friendlyCountry->setResearch(this->friendlyCountry->getResearch() + change);
    Logger::log("Research increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName() + "\n");
}
