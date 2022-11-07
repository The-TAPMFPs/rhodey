#include "Tank.h"

/**
 * @file Tank.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Tank(string name, int numberOfTroops, 
 vector<Weapon*>* weapons, Country * country)
 * @brief Construct a new Truck:: Truck object
 *  
 * @param name The name of the Tanks. 
 * @param numberOfTroops The amount of Tanks to make.
 * @param weapons The weapons that the Tanks use.
 * @param country The Country that the Tanks belong too.
 */

Tank::Tank(string name, int numberOfTroops, vector<Weapon *> * weapons, Country * country) :
    GroundVehicle(name, numberOfTroops, 500, 30, weapons, country, "Tank") {
	this->terrianHandling = 50;
	this->capacity = 5;
    };

/**
 * @fn Entity* splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief  Allows for the Tank to be cloned
 * 
 * @param name The name of the Tanks. 
 * @param numberOfTroops The amount of Tanks to make.
 * @param weapons The weapons that the Tanks use. 
 * @return Entity* 
 */
Entity * Tank::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Tank(name, numberOfTroops, weapon, this->country);
}

/**
 * @fn int weaknesses(int damage, Weapon & weapon)
 * @brief An additional damage modifier that ensures that that certain weapons do no damage.
 * 
 * @param damage The amount of potential damage from the base Entity.
 * @param weapon A weapon that is used against a Tank. 
 * @return int total
 */
int Tank::weaknesses(int damage, Weapon & weapon) {
    int total = GroundVehicle::weaknesses(damage, weapon);
    if (weapon.getType() == SMALL_ARMS) {
	total = 0;
    }
    if (weapon.getType() == HIGH_CAL) {
	total = 0;
    }
    return total;
}
