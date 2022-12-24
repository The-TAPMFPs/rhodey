#include "TroopFactory.h"
#include <algorithm>
#include <sstream>
#include <vector>
#include "Entities/Troop/Troop.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "../MapRegions/Map.h"
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
}

/**
 * @fn ~TroopFactory()
 * @brief The Destructor of the TroopFactory class.
 */
TroopFactory::~TroopFactory(){
}

/**
 * @fn getWeapons (int numberOfTroops)
 * @brief Returns the weapons that entities will be armed with.
 * @param numberOfEntities The number of entities that need to be armed
 * @returns std::vector<Weapon *>
 */
std::vector<Weapon *> * TroopFactory::getWeapons(int numberOfEntities) {
    /**<Vector which contains a set of references to weapon objects>*/
    std::vector<Weapon *> * weaponsToReturn = new std::vector<Weapon *>;
    int weaponTypeArraySize = 0;
    WEAPON_NAME * weaponTypeArray = NULL;
    int specialWeaponsArraySize = 0;
    WEAPON_NAME * specialWeaponsArray = NULL;

    if(this->country->getResearch() < 0.2){
	weaponTypeArray = new WEAPON_NAME[2] {CLASS_SMG, CLASS_PISTOL};
	weaponTypeArraySize = 2;
    } else if(this->country->getResearch() < 0.5){
	weaponTypeArray = new WEAPON_NAME[3] {CLASS_AR, CLASS_PISTOL};
	weaponTypeArraySize = 3;
	specialWeaponsArray = new WEAPON_NAME[1] {CLASS_SNIPER};
	specialWeaponsArraySize = 1;
    } else if(this->country->getResearch() < 0.8){
	weaponTypeArray = new WEAPON_NAME[3] {CLASS_AR, CLASS_SMG, CLASS_DUALBURETTE};
	weaponTypeArraySize = 3;
	specialWeaponsArray = new WEAPON_NAME[1] {CLASS_BAZOOKA};
	specialWeaponsArraySize = 1;
    } else if(this->country->getResearch() <= 1){
	weaponTypeArray = new WEAPON_NAME [2] {CLASS_AK47,CLASS_DUALBURETTE};
	weaponTypeArraySize = 2;
	specialWeaponsArray = new WEAPON_NAME [2] {CLASS_SNIPER50, CLASS_BAZOOKA};
	specialWeaponsArraySize = 2;
    }

    if (weaponTypeArray != NULL) {
	for (int count = 0; count*40 < numberOfEntities; count++) {
	    Weapon * weapon = this->weapons->getWeapon(
		    weaponTypeArray[count%weaponTypeArraySize]);
	    weaponsToReturn->push_back(weapon);
	}
    }
    if (specialWeaponsArray != NULL) {
	for (int count = 0; count*100 < numberOfEntities; count++) {
	    Weapon * weapon = this->weapons->getWeapon(
		    specialWeaponsArray[count%specialWeaponsArraySize]);
	    weaponsToReturn->push_back(weapon);
	}
    }
    // gen is from uuid.h
    std::shuffle(weaponsToReturn->begin(), weaponsToReturn->end(), gen);
    return weaponsToReturn;
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
    weaponVector = getWeapons(numberOfTroops);

    //Create Troops
    std::string someName = this->name + " " + this->incAndGetBatalionNumber();
    result = new Troop(someName,numberOfTroops,weaponVector,this->country);

    this->ouputCreationFlair(*weaponVector);
    this->country->getMap()->getOccupancyTable()->addEntity(result,
	    this->country->getCapital());
    return result;
}


