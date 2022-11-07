#include "CargoShip.h"

/**
 * @file CargoShip.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn CargoShip(string name, int numberOfTroops, 
 vector<Weapon*>* weapons, Country * country)
 * @brief Construct a new CargoShip:: CargoShip object
 *  
 * @param name The name of the CargoShips. 
 * @param numberOfTroops The amount of CargoShips to make.
 * @param weapons The weapons that the CargoShips use.
 * @param country The Country that the CargoShips belong too.
 */
CargoShip::CargoShip(string name, int numberOfTroops,
	vector<Weapon *> * weapons, Country * country) : WaterVehicle(name,
	    numberOfTroops, 1000, 20, weapons, country, "CargoShip") {
	this->terrianHandling = 32;
	this->capacity = 2000;
    };

/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief Allows for the CargoShip to be cloned
 * 
 * @param name The name of the CargoShips. 
 * @param numberOfTroops The amount of CargoShips to make.
 * @param weapons The weapons that the CargoShips use.
 * @return Entity * CargoShip
 */
Entity * CargoShip::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new CargoShip(name, numberOfTroops, weapon, this->country);
}
