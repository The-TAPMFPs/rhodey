#include "Bomber.h"

/**
 * @file Bomber.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Bomber(string name, int numberOfTroops, 
 vector<Weapon*>* weapons, Country * country)
 * @brief Construct a new Bomber:: Bomber object
 *  
 * @param name The name of the Bombers. 
 * @param numberOfTroops The amount of Bombers to make.
 * @param weapons The weapons that the Bombers use.
 * @param country The Country that the Bombers belong too.
 */
Bomber::Bomber(string name, int numberOfTroops, vector<Weapon*>* weapons,
	Country * country) : AirVehicle(name, numberOfTroops, 100, 42, weapons,
	    country, "Bomber") {
	this->terrianHandling = 50;
	this->capacity = 30;
};

/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief Allows for the Bomber to be cloned
 * 
 * @param name The name of the Bombers. 
 * @param numberOfTroops The amount of Bombers to make.
 * @param weapons The weapons that the Bombers use.
 * @return Entity * Bomber
 */
Entity * Bomber::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Bomber(name, numberOfTroops, weapon, this->country);
}
