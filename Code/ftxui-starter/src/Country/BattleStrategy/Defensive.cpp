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

/**
 * @fn void doStrategy(Country* country)
 * @brief determines which function should be used in this strategy.
 * 
 * @param country A reference to the country calling the strategy.
 */
void Defensive::doStrategy(Country* country){
    // if there is a non contesting region, move those troops to a contesting
      // region if no contesting region then recruit this->strategy = new
      // Defensive();
}
/**
 * @fn void setNameNumCont(string name, int num, Country * con)
 * @brief A setter for the name, num and country of troops that will be made.
 * 
 * @param name The name of troops.
 * @param num The amount of troops to be made.
 * @param con The country that the troops belong too.
 */
void Defensive::setNameNumCont(std::string name, int num, Country * con){
    _name = name;
    _num = num;
    _con = con;
}

/**
 * @fn void redistributeTroops()
 * @brief Moves troops to a more defensive position.
 * 
 */
void Defensive::redistributeTroops(){
    OccupancyTable* occTable = map->getOccupancyTable();
    occTable->moveEntity(occTable->getEntities(friendlyRegion), enemyRegion);
    Logger::log(this->friendlyCountry->getName() + " has moved troops from " + this->friendlyRegion->getRegionName() + " to " + this->enemyRegion->getRegionName() + "\n");
    delete occTable;
    
}

/**
 * @fn void recruitTroops()
 * @brief Makes a new Troop Factory, makes new Units and then deletes the Troop Factory. 
 * 
 */
void Defensive::recruitTroops(){
    uf = new TroopFactory(_name, _num, _con);
    uf->makeUnit();
    delete uf;
}

/**
 * @fn void setFriendlyRegion(Region* friendlyRegion)
 * @brief A setter for a Region that a country can move too.
 * 
 * @param friendlyRegion A Region reference to a region that is an ally.
 */
void Defensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

/**
 * @fn void setEnemyRegion(Region* enemyRegion)
 * @brief A setter for a Region that is owned by an enemy of a country.
 * 
 * @param friendlyRegion A Region reference to a region that is an enemy.
 */
void Defensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}


