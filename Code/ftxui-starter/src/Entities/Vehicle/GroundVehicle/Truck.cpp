#include "Truck.h"

/**
 * @file Truck.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Truck(string name, int numberOfTroops, 
 vector<Weapon*>* weapons, Country * country)
 * @brief Construct a new Truck:: Truck object
 *  
 * @param name The name of the Trucks. 
 * @param numberOfTroops The amount of Trucks to make.
 * @param weapons The weapons that the Trucks use.
 * @param country The Country that the Trucks belong too.
 */
Truck::Truck(string name, int numberOfTroops, vector<Weapon *> * weapons,
	Country * country) : GroundVehicle(name, numberOfTroops, 100, 10,
	    weapons, country, "Truck") {
	this->terrianHandling = 32;
	this->capacity = 30;
    };

/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief  Allows for the Truck to be cloned
 * 
 * @param name The name of the Trucks. 
 * @param numberOfTroops The amount of Trucks to make.
 * @param weapons The weapons that the Trucks use. 
 * @return Entity* Truck
 */
Entity * Truck::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Truck(name, numberOfTroops, weapon, this->country);
}
