#include "Prepare.h"

/**
 * @file Prepare.cpp
 * @brief Construct a new Prepare Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Prepare()
 * @brief The constructor for the Prepare class.
 * 
 */
Prepare::Prepare(){
}

/**
 * @fn void warAlgorithm(int prep)
 * @brief Decides on which strategy algorithm to use based on an enum.
 * 
 * @param prep An int that is converted to an enum and switched to decide on the strategy.
 */
void Prepare::warAlgorithm(int prep){
    this->prep =(_prep) prep;
    switch(prep){
        case recP:
            recruitTroops();
            break;
        case bvP:
            buildVehicles();
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
void Prepare::setNameNumCont(std::string name, int num, Country *con){
    _name = name;
    _num = num;
    _con = con;
}

/**
 * @fn void setVehicle(string name, int num,  VEHICLE_TYPE veh, Country * con)
 * @brief A setter for the name, num, vehicle type and country of vehicles that will be made.
 * 
 * @param name The name of the vehicles.
 * @param num The amount of vehicels to be made.
 * @param veh The type of vehicle to be made
 * @param con The country that the vehicles belong too.
 */
void Prepare::setVehicle(std::string name, int num, VEHICLE_TYPE veh, Country * con){
    _name = name;
    _num = num;
    _veh = veh;
    _con = con;
}

/**
 * @fn void recruitTroops()
 * @brief Makes a new Troop Factory, makes new Units and then deletes the Troop Factory. 
 * 
 */
void Prepare::recruitTroops(){
    uf = new TroopFactory(_name, _num, _con);
    uf->makeUnit();
    delete uf;
}

/**
 * @fn void buildVehicles()
 * @brief Makes a new Vehicle Factory, makes new Vehicels and then deletes the Vehicle Factory. 
 * 
 */
void Prepare::buildVehicles(){
    vf = new VehicleFactory(_name, _num, _veh, _con);
    vf->makeUnit();
    delete vf;
}

/**
 * @fn void setFriendlyRegion(Region* friendlyRegion)
 * @brief A setter for a Region that a country can move too.
 * 
 * @param friendlyRegion A Region reference to a region that is an ally.
 */
void Prepare::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

/**
 * @fn void setEnemyRegion(Region* enemyRegion)
 * @brief A setter for a Region that is owned by an enemy of a country.
 * 
 * @param friendlyRegion A Region reference to a region that is an enemy.
 */
void Prepare::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}

