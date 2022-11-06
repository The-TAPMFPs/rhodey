#pragma once

#include "UnitFactory.h"
#include "../Country/Country.h"
#include "../Entities/Troop/Troop.h"

class TroopFactory : public UnitFactory{
    public:
        TroopFactory(std::string name, int num, Country * con);
        ~TroopFactory();
        Entity* makeUnit();
};
