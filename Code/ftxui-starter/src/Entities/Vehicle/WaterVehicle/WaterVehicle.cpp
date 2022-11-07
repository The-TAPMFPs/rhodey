#include "WaterVehicle.h"

/**
 * @file WaterVehicle.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn WaterVehicle(string name, int numberOfTroops, int HP, int Damage,
 vector<Weapon*> * weapon, Country * country, std::string type)
 * @brief Construct a new Water Vehicle object :: Water Vehicle object
 * 
 * @param name The name of the Water Vehicles
 * @param numberOfTroops The amount of Water Vehicles
 * @param HP The Hit Points of the Water Vehicles
 * @param Damage The base amount of damage of the Water Vehicles
 * @param weapon The weapons the Water Vehicle will have
 * @param country The country thre Water Vehicles belong too
 * @param type The type of Water Vehicle
 */
WaterVehicle::WaterVehicle(string name, int numberOfTroops, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country, std::string type) :
    Vehicle(name, numberOfTroops, HP, Damage, weapon, country, type){};

/**
 * @fn int weakness(int damage, Weapon & weapon)
 * @brief Calculates the damage that could be done against the current 
 *        vehicle based on the weapon used against them. 
 * 
 * @param damage The amount of potential damage from the base Entity.
 * @param weapon A weapon that is used against a Vehicle.
 * @return int totalDamage
 */
int WaterVehicle::weaknesses(int damage,Weapon & weapon) {
    int totalDamage = damage;
    if (weapon.getType() == BOMB) {
	totalDamage = totalDamage*2;
    }
    if (weapon.getType() == ROCKET) {
	totalDamage = totalDamage*1.4;
    }
    if (weapon.getType() == CANNON) {
	totalDamage = totalDamage*1.4 + weapon.getDamage();
    }
    return totalDamage;
}
