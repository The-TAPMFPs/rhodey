#include "Submarine.h"

/**
 * @file Submarine.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Submarine(string name, int numberOfTroops, 
 vector<Weapon*>* weapons, Country * country)
 * @brief Construct a new Submarine:: Submarine object
 *  
 * @param name The name of the Submarines. 
 * @param numberOfTroops The amount of Submarines to make.
 * @param weapons The weapons that the Submarines use.
 * @param country The Country that the Submarines belong too.
 */
Submarine::Submarine(string name, int numberOfTroops,
	vector<Weapon *> * weapons, Country * country) : WaterVehicle(name,
	    numberOfTroops, 100, 42, weapons, country, "Submarine") {
	this->terrianHandling = 32;
	this->capacity = 30;
    };

/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief Allows for the Submarine to be cloned
 * 
 * @param name The name of the Submarines. 
 * @param numberOfTroops The amount of Submarines to make.
 * @param weapons The weapons that the Submarines use.
 * @return Entity * Submarine
 */
Entity * Submarine::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Submarine(name, numberOfTroops, weapon, this->country);
}
