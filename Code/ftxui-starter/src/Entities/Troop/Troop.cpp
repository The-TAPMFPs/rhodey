#include "Troop.h"

/**
 * @file Troop.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022 
 */

/**
 * @fn Troop(string name, int numberOfTroops, vector<Weapon*> * weapon, Country * country)
 * @brief Construct a new Troop:: Troop object
 * 
 * @param name The name of the troop.
 * @param numberOfTroops The amount of troops to make, corresponds to the HP of the troop.
 * @param weapon The weapons that the troops will use.
 * @param country The country that the troop belongs too.
 */
Troop::Troop(string name, int numberOfTroops, vector<Weapon*> * weapon, Country * country) :
    Entity(name, "Ground Infantry", numberOfTroops, 3, weapon, country) {
	this->HPScalling = 3;
	this->HP = this->HP* this->HPScalling;
    }

/**
 * @fn getCarryingCapacity
 * @brief 
 * 
 * @return int 
 */
int Troop::getCarryingCapacity() {
    return 1;
}

/**
 * @fn EntitysplitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * @brief Clones the troop Entity
 * 
 * @param name The name of the troop.
 * @param numberOfTroops The amount of troops to make, corresponds to the HP of the troop.
 * @param weapon The weapons that the troops will use. 
 * @return Entity* 
 */
Entity * Troop::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Troop(name, numberOfTroops, weapon, this->country);
}

/**
 * @fn int weaknesses(int damage, Weapon& weapon)
 * @brief Calculates the damage that could be done against the current 
 *        troop based on the weapon used against them.
 * 
 * @param damage The amount of potential damage from the base Entity.
 * @param weapon A weapon that is used against a troop.
 * @return int 
 */
int Troop::weaknesses(int damage, Weapon& weapon) {
    int potentialDamage = damage * log10(damage* weapon.getDamage());
    if (weapon.getType() == ANTI_TANK) {
	potentialDamage = this->HP/damage;
    }
    return potentialDamage;
}

/**
 * @fn getTerrainHandling()
 * @brief Used to determine difficulty of moving between regions.
 * 
 * @return int 
 */
int Troop::getTerrainHandling() {
    return 3;
}
