#include "Carrier.h"

/**
 * @file Carrier.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Carrier(string name, int numberOfTroops, 
 vector<Weapon*>* weapons, Country * country)
 * @brief Construct a new Carrier:: Carrier object
 *  
 * @param name The name of the Carriers. 
 * @param numberOfTroops The amount of Carriers to make.
 * @param weapons The weapons that the Carriers use.
 * @param country The Country that the Carriers belong too.
 */
Carrier::Carrier(string name, int numberOfTroops, vector<Weapon *> * weapons,
	Country * country) : WaterVehicle(name, numberOfTroops, 1000, 90,
	    weapons, country, "Carrier") {
	this->terrianHandling = 32;
	this->capacity = 3000;
    };

/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief Allows for the Carrier to be cloned
 * 
 * @param name The name of the Carriers. 
 * @param numberOfTroops The amount of Carriers to make.
 * @param weapons The weapons that the Carriers use.
 * @return Entity * Carrier
 */
Entity * Carrier::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Carrier(name, numberOfTroops, weapon, this->country);
}
