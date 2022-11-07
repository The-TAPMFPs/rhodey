#include "ResearchAndDevelopment.h"

/**
 * @file Defensive.cpp
 * @brief Construct a new ResearchAndDevelopment Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn ResearchAndDevelopment()
 * @brief The constructor for the ResearchAndDevelopment class
 * 
 */
ResearchAndDevelopment::ResearchAndDevelopment(){
    
}

/**
 * @fn void warAlgorithm(int rad)
 * @brief Decides on which strategy algorithm to use based on an enum.
 * 
 * @param rad An int that is converted to an enum and switched to decide on the strategy.
 */
void ResearchAndDevelopment::warAlgorithm(int rad){
    this->rad =(_rad) rad;
    switch(rad){
        case drRD:
            developResources();
            break;
        case deRD:
            developEconomy();
            break;
        case rRD:
            research();
            break;
    }
    return;
}


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
    Logger::log("Message here on what the country does");
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
    Logger::log("Resources increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName());
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
    Logger::log("Economy increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName());
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
    Logger::log("Research increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName());

}


/**
 * @fn void setFriendlyCountry(Country* friendly)
 * @brief a setter for the friendlyCountry variable.
 * 
 * @param friendly holds a reference to the country which called the algorithm.
 */
void ResearchAndDevelopment::setFriendlyCountry(Country* friendly){
    this->friendlyCountry = friendly;
}