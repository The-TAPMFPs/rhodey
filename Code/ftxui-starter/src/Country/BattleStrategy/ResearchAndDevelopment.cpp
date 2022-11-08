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
    switch(uuid::randomInt(0, 1))
    {
        case 0:
            country->setResearch(country->getResearch() + 0.1);
            break;
        case 1:
            country->setResources(country->getResources() + 0.1);
            break;
    }
}