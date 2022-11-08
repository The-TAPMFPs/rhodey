#include "BattleStrategy.h"

/**
 * @file BattleStrategy.cpp
 * @brief Construct a new Battle Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn BattleStrategy(Map* map)
 * @brief The constructor of the BattleStrategy class.
 * 
 * @param map allows access to the map
 */ 
BattleStrategy::BattleStrategy(Map* map) {
    this->map = map;
}

/**
 * @fn ~BattleStrategy()
 * @brief The destructor of the BattleStrategy class.
 */ 
BattleStrategy::~BattleStrategy() {}
