#include "CargoPlane.h"

/**
 * @file CargoPlane.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn CargoPlane(string name, int numberOfTroops,
vector<Weapon *> * weapons, Country * country)
 * @brief Construct a new Cargo Plane:: Cargo Plane object
 * 
 * @param name The name of the Cargo Planes.
 * @param numberOfTroops The amount of Cargo Planes.
 * @param weapons The Weapons of the Cargo Planes.
 * @param country The country that the Cargo Planes belong too.
 */
CargoPlane::CargoPlane(string name, int numberOfTroops,
	vector<Weapon *> * weapons, Country * country) : AirVehicle(name,
	    numberOfTroops, 100, 0, weapons, country, "CargoPlane") {
	this->terrianHandling = 50;
	this->capacity = 30;
    };

/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief Allows for the CargoPlane to be cloned
 * 
 * @param name The name of the Cargo Planes.
 * @param numberOfTroops The amount of Cargo Planes.
 * @param weapons The Weapons of the Cargo Planes.
 * @return Entity * CargoPlane
 */
Entity * CargoPlane::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new CargoPlane(name, numberOfTroops, weapon, this->country);
}
