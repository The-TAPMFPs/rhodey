#pragma once
#include <memory>
#include <vector>
#include "Entities/Entity.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "Entities/WeaponTemplateMethod/WeaponFlyWeightFactory.h"
#include "logger.h"
#include <climits>

class Country;
class UnitFactory{
    protected:
	shared_ptr<WeaponFlyweightFactory> weapons;
        std::string name;
	int batalionNumber;
        int num; // Max Number of entities that factory can produce given
	         // perfect stability of country.
        Country * country;
	// Creates weapons for troops
	virtual std::vector<Weapon *> * getWeapons(int numberOfEntities) = 0;
	virtual void ouputCreationFlair(vector<Weapon *> weapons);
	virtual int numberToProduce(int num = INT_MIN);
	std::string incAndGetBatalionNumber();
    public:
        UnitFactory(std::string name, int num, Country * con);
	virtual ~UnitFactory();
        virtual Entity* makeUnit() = 0;
};
