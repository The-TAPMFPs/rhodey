#pragma once

#include "UnitFactory.h"
#include "Entities/Troop/Troop.h"

class TroopFactory : public UnitFactory{
    protected:
	std::vector<Weapon *> * getWeapons(int numberOfEntities);
    public:
        TroopFactory(std::string name, int num, Country * con);
        ~TroopFactory();
        Entity* makeUnit();
};
