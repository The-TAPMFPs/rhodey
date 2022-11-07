#include "Warship.h"

/**
 * @file Warship.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Warship(string name, int numberOfTroops, 
 vector<Weapon*>* weapons, Country * country)
 * @brief Construct a new Warship:: Warship object
 *  
 * @param name The name of the Warships. 
 * @param numberOfTroops The amount of Warships to make.
 * @param weapons The weapons that the Warships use.
 * @param country The Country that the Warships belong too.
 */
Warship::Warship(string name, int numberOfTroops, vector<Weapon *> * weapons,
	Country * country) : WaterVehicle(name, numberOfTroops, 1000, 100,
	    weapons, country, "Warship") {
	this->terrianHandling = 32;
	this->capacity = 2000;
    };

/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief Allows for the Warship to be cloned
 * 
 * @param name The name of the Warships. 
 * @param numberOfTroops The amount of Warships to make.
 * @param weapons The weapons that the Warships use.
 * @return Entity * Warship
 */
Entity * Warship::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Warship(name, numberOfTroops, weapon, this->country);
}
