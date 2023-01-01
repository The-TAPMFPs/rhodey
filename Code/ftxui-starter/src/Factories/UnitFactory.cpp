#include "UnitFactory.h"
#include <climits>
#include <exception>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "Country/Country.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"

UnitFactory::UnitFactory(std::string name, int num, Country * con)
 : name(name), num(num), country(con)
{
    weapons = this->country->getWeaponFlyweightFactory();
    this->batalionNumber = 1;
}

UnitFactory::~UnitFactory() {
}

void UnitFactory::ouputCreationFlair(vector<Weapon *> weapons, Entity * entity) {
    std::stringstream convert; /**<A stringstream to concentate the intital message.>*/
    std::map<std::string,std::string> uniqueNames; /**<The only reason a map is
						     used here is becuase it is
						     fast and i didn't want to
						     create a new data structure
						     just for lookups>*/
    convert << "A battalion of " << entity->getType() << " armed with: ";
    for (int count = 0; count < weapons.size(); count++) { // get all the unique names
	if (uniqueNames.find(weapons.at(count)->getName()) == uniqueNames.end()) {
	    uniqueNames.emplace(
	      pair<std::string, std::string>(
		weapons.at(count)->getName(),
		weapons.at(count)->getName()
		)
	      );
	}
    }

    // Iterate through all the unique names to build a string.
    if (uniqueNames.begin() != uniqueNames.end()) {
	for (auto iter = uniqueNames.begin(); iter != --uniqueNames.end(); ++iter) {
	    convert << iter->second << ", ";
	}
	convert << "and " << (--uniqueNames.end())->second;
    }
    convert << " were recruited.";
    Logger::log(convert.str());
}

int UnitFactory::numberToProduce(int num) {
    int toReturn = 1000;
    if (num != INT_MIN) {
	if (this->country->getPopulation() < 1000000) {
	    toReturn = num;
	}
    }
    return toReturn;
}

std::string UnitFactory::incAndGetBatalionNumber() {
    this->batalionNumber = this->batalionNumber%20;
    std::stringstream temp;
    temp << ++this->batalionNumber;
    return temp.str();
}

/**
 * @fn getWeapons (int numberOfTroops)
 * @brief Returns the weapons that entities will be armed with.
 * @param numberOfEntities The number of entities that need to be armed
 * @returns std::vector<Weapon *>
 */
std::vector<Weapon *> * UnitFactory::getWeapons(int numberOfEntities,
	ENTITY_TYPE type, int primaryLoopModifier, int secondaryLoopModifier) {
    /**<Vector which contains a set of references to weapon objects>*/
    std::vector<Weapon *> * weaponsToReturn = new std::vector<Weapon *>;
    pair<vector<WEAPON_NAME>,vector<WEAPON_NAME>> weaponSet;
    try {
	weaponSet = this->selectWeaponSet(type);
    } catch(exception e) {
	weaponSet = make_pair(vector<WEAPON_NAME>(), vector<WEAPON_NAME>());
    }

    if (weaponSet.first.size() != 0) {
	for (int count = 0; count*primaryLoopModifier < numberOfEntities; count++) {
	    Weapon * weapon = this->weapons->getWeapon(
		    weaponSet.first[count%weaponSet.first.size()]);
	    weaponsToReturn->push_back(weapon);
	}
    }
    if (weaponSet.second.size() != 0) {
	for (int count = 0; count*secondaryLoopModifier < numberOfEntities; count++) {
	    Weapon * weapon = this->weapons->getWeapon(
		    weaponSet.second[count%weaponSet.second.size()]);
	    weaponsToReturn->push_back(weapon);
	}
    }

    // gen is from uuid.h
    std::shuffle(weaponsToReturn->begin(), weaponsToReturn->end(), gen);
    return weaponsToReturn;
}

pair<vector<WEAPON_NAME>,vector<WEAPON_NAME>> UnitFactory::selectWeaponSet(ENTITY_TYPE type) {
    float intervals = float (1)/((this->weaponSets.at(type).size()==0) ? 1 : this->weaponSets.at(type).size());
    int setIndexToReturn = this->country->getResearch()/intervals;
    pair<vector<WEAPON_NAME>,vector<WEAPON_NAME>> toReturn = this->weaponSets.find(type)->second.at(setIndexToReturn);
    return toReturn;
}
