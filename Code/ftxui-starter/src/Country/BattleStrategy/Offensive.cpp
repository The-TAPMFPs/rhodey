#include "Offensive.h"

/**
 * @file Offensive.cpp
 * @brief Construct a new Offensive Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Offensive()
 * @brief The constructor for the Offensive class.
 * 
 */
Offensive::Offensive(){
    
}

/**
 * @fn void warAlgorithm(int off)
 * @brief Decides on which strategy algorithm to use based on an enum.
 * 
 * @param off An int that is converted to an enum and switched to decide on the strategy.
 */
void Offensive::warAlgorithm(int off){
    this->off =(_off) off;
    switch(off){
        case redOff:
            redistributeTroops();
            break;
        case attOff:
            attack();
            break;
    }
    return;
}


void Offensive::doStrategy(Country* country){
    Logger::log("Do the offensive strategy");
}

/**
 * @fn void redistributeTroops
 * @brief Moves troops from one position to another in order to improve defense.
 * 
 */
void Offensive::redistributeTroops(){

}

/**
 * @fn void attack()
 * @brief Informs a country that it is in a position to take an aggresive stance against an enemy.
 * 
 */
void Offensive::attack(){

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
