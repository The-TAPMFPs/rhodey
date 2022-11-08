#include "Prepare.h"

/**
 * @file Prepare.cpp
 * @brief Construct a new Prepare Strategy object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Prepare(Map* map)
 * @brief The constructor for the Prepare class.
 * 
 * @param map allows access to the map
 */
Prepare::Prepare(Map* map) : BattleStrategy(map){}


void Prepare::doStrategy(Country* country){
    double troopNeed = ((country->getNumTroops() == 0) ? 1 : 1 - (country->getNumTroops() / (0.3 * country->getPopulation())));
    double vehicleNeed = ((country->getNumTroops()==0) ? 1 : 1 - (country->getNumVehicles() / (country->getNumTroops() / 10)));
    if(troopNeed >= vehicleNeed){
        recruitTroops();
    } else {
        buildVehicles();
    }

    srand((unsigned)time(NULL));
    double change = (((double) rand() / RAND_MAX) * 0.05-0.01) + 0.01;
    country->setResources(this->friendlyCountry->getResources() - change);
    country->setEconomy(this->friendlyCountry->getEconomy() - change);
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
    uf = new VehicleFactory(_name, _num, _veh, _con);
    uf->makeUnit();
    delete uf;
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

