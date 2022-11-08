#include "Offensive.h"

/**
 * @file Offensive.cpp
 * @brief Construct a new Offensive Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Offensive(Map* map)
 * @brief The constructor for the Offensive class.
 *
 * @param map allows access to the map
 */
Offensive::Offensive(Map* map) : BattleStrategy(map) {}

/**
 * @fn void doStrategy(Country* country)
 * @brief determines which function should be used in this strategy.
 * 
 * @param country A reference to the country calling the strategy.
 */
void Offensive::doStrategy(Country* country){
    //enemyRergion = region with highest friendly ratio
    //friendlyRegion = region with lowest enemy ratio
}

/**
 * @fn void redistributeTroops
 * @brief Moves troops from one position to another in order to improve defense.
 * 
 */
void Offensive::redistributeTroops(){
    //move troops from region with lowest enemy troop count to region with highest friendly ratio
    OccupancyTable* occTable = map->getOccupancyTable();
    occTable->moveEntity(occTable->getEntities(friendlyRegion), enemyRegion);
    delete occTable;
}

/**
 * @fn void attack()
 * @brief Informs a country that it is in a position to take an aggresive stance against an enemy.
 * 
 */
void Offensive::attack(){
    OccupancyTable* occTable = map->getOccupancyTable();
    Battle* battle = new Battle(enemyRegion, occTable);
    while(battle->takeTurn()){

    }

    delete battle;
    delete occTable;
}

/**
 * @fn void setFriendlyRegion(Region* friendlyRegion)
 * @brief A setter for a Region that a country can move too.
 * 
 * @param friendlyRegion A Region reference to a region that is an ally.
 */
void Offensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

/**
 * @fn void setEnemyRegion(Region* enemyRegion)
 * @brief A setter for a Region that is owned by an enemy of a country.
 * 
 * @param friendlyRegion A Region reference to a region that is an enemy.
 */
void Offensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}
