#include "Defensive.h"

/**
 * @file Defensive.cpp
 * @brief Construct a new Defenseive Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Defensive(Map* map)
 * @brief The constructor for the Defensive class
 * 
 * @param map allows access to the map
 */
Defensive::Defensive(Map* map) : BattleStrategy(map){}


void Defensive::doStrategy(Country* country){
}