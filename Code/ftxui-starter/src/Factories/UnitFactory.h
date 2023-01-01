#pragma once
#include <functional>
#include <memory>
#include <vector>
#include "Entities/Entity.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "Entities/WeaponTemplateMethod/WeaponFlyWeightFactory.h"
#include "logger.h"
#include <climits>
#include <map>

enum ENTITY_TYPE {
    TRUCK, TANK, CARRIER, CARGOSHIP, WARSHIP, SUBMARINE, FIGHTERJET, BOMBER,
    CARGOPLANE, TROOP
};
class Country;
class UnitFactory{
    protected:
	shared_ptr<WeaponFlyweightFactory> weapons;
        std::string name;
	int batalionNumber;
        int num; // Max Number of entities that factory can produce given
	         // perfect stability of country.
        Country * country;
	// WeaponName vectors used to store sets of weapons used for different
	//    levels of advancement.
	std::map<
	    int,
	    std::vector<
		std::pair<
		vector<WEAPON_NAME>,
	        vector<WEAPON_NAME>
		>
	    >> weaponSets;
	// Creates weapons for troops
	virtual std::vector<Weapon *> * getWeapons(int numberOfEntities,
		ENTITY_TYPE,
		int primaryLoopModifier = 40,
		int secondarLoopModifier = 100);
	virtual void ouputCreationFlair(vector<Weapon *> weapons, Entity *);
	virtual int numberToProduce(int num = INT_MIN);
	pair<vector<WEAPON_NAME>,vector<WEAPON_NAME>> selectWeaponSet(ENTITY_TYPE);
	std::string incAndGetBatalionNumber();
    public:
        UnitFactory(std::string name, int num, Country * con);
	virtual ~UnitFactory();
        virtual Entity* makeUnit() = 0;
};
