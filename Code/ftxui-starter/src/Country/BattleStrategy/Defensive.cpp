#include "Defensive.h"

/**
 * @file Defensive.cpp
 * @brief Construct a new Defenseive Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Defensive()
 * @brief The constructor for the Defensive class
 * 
 */
Defensive::Defensive(){}

/**
 * @fn void warAlgorithm(int def)
 * @brief Decides on which strategy algorithm to use based on an enum.
 * 
 * @param def An int that is converted to an enum and switched to decide on the strategy.
 */
void Defensive::warAlgorithm(int def){
    this->def =(_def) def;

    switch(def){
        case redDef:
            redistributeTroops();
            break;
        case recDef:
            recruitTroops();
            break;
    }
    return;
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
 * @fn void setDef(_def def)
 * @brief A setter for the enum def.
 * 
 * @param def An enum that determines the defensive strategy.
 */
void Defensive::setDef(_def def){
    this->def = def;
}

/**
 * @fn void redistributeTroops
 * @brief Moves troops from one position to another in order to improve defense.
 * 
 */
void Defensive::redistributeTroops(){
    
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


