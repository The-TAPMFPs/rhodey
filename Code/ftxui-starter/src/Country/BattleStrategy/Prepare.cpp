#include "Prepare.h"
#include <algorithm>
#include "Factories/TroopFactory.h"

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
Prepare::Prepare(Map* map, Country * country) : BattleStrategy(map){
    this->map = map;
    this->troopFactory = new TroopFactory((country->getName() + "'s Training Facility"), 1000, country);
    this->vehicleFactory = new VehicleFactory((country->getName() + "'s Factory"), 100, country);
}

Prepare::~Prepare() {
    delete this->troopFactory;
    delete this->vehicleFactory;
}


void Prepare::doStrategy(Country* country){
    this->troopFactory->makeUnit();
    this->vehicleFactory->makeUnit();
}
