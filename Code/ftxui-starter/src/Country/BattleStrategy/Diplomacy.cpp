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
}