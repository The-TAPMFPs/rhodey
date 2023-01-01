#include "TroopFactory.h"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>
#include "Entities/Troop/Troop.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "../MapRegions/Map.h"
#include "Factories/UnitFactory.h"
#include "uuid.h"

/**
 * @file TroopFactory.cpp
 * @brief Construct a new Troop Factory object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022
 */

/**
 * @fn TroopFactory (std::string name, int num, Country * con)
 * @brief The constructor of the TroopFactory class.
 *
 * @param name Troop Name
 * @param num Amount of Troops factory is capable of producing.
 * @param con Country of Troops
 */
TroopFactory::TroopFactory(std::string name, int num, Country * con) :
    UnitFactory(name, num, con) {
	this->weaponSets.insert({TROOP, vector<pair<vector<WEAPON_NAME>,vector<WEAPON_NAME>>>()});
	this->weaponSets.at(TROOP).push_back(
		pair<vector<WEAPON_NAME>,vector<WEAPON_NAME>>(
		    vector<WEAPON_NAME> {CLASS_SMG, CLASS_PISTOL},
		    vector<WEAPON_NAME> {CLASS_BAZOOKA}
		));
	this->weaponSets.at(TROOP).push_back(
		make_pair(
		    vector<WEAPON_NAME> {CLASS_AR, CLASS_PISTOL},
		    vector<WEAPON_NAME> {CLASS_BAZOOKA,CLASS_SNIPER}
		));
	this->weaponSets.at(TROOP).push_back(
		make_pair(
		    vector<WEAPON_NAME> {CLASS_AR, CLASS_SMG, CLASS_DUALBURETTE},
		    vector<WEAPON_NAME> {CLASS_BAZOOKA,CLASS_SNIPER}
		));
	this->weaponSets.at(TROOP).push_back(
		make_pair(
		    vector<WEAPON_NAME> {CLASS_AK47,CLASS_DUALBURETTE},
		    vector<WEAPON_NAME> {CLASS_SNIPER50, CLASS_BAZOOKA}
		));
}

/**
 * @fn ~TroopFactory()
 * @brief The Destructor of the TroopFactory class.
 */
TroopFactory::~TroopFactory(){
}

/**
 * @fn Entity* makeUnit()
 * @brief Makes the specific units based on chance and research level
 *        and returns a reference to the new Entity that has been made.
 */
Entity* TroopFactory::makeUnit(){
    vector<Weapon *> * weaponVector;
    Troop * result;

    // TODO: Create the weapons and the troops
    // Determine amount of troops to be made based on the state of the country
    int numberOfTroops = this->numberToProduce();
    // Create weapons
    weaponVector = getWeapons(numberOfTroops, TROOP);

    //Create Troops
    std::string someName = this->name + " " + this->incAndGetBatalionNumber();
    result = new Troop(someName,numberOfTroops,weaponVector,this->country);

    this->ouputCreationFlair(*weaponVector, result);

    this->country->getMap()->getOccupancyTable()->addEntity(result,
	    this->country->getCapital());
    return result;
}


