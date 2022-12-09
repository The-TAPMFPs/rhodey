#pragma once
#include <memory>
#include "Entities/Entity.h"
#include "Entities/WeaponTemplateMethod/WeaponFlyWeightFactory.h"
#include "logger.h"

class Country;
class UnitFactory{
    protected:
	shared_ptr<WeaponFlyweightFactory> weapons;
        std::string name;
        int num; // Max Number of entities that factory can produce given
	         // perfect stability of country.
        Country * country;
    public:
        UnitFactory(std::string name, int num, Country * con);
	virtual ~UnitFactory();
        virtual Entity* makeUnit() = 0;


};
