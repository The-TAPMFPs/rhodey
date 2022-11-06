#pragma once

#include "UnitFactory.h"

class TroopFactory : public UnitFactory{
    public:
        TroopFactory(std::string name, int num, Country * con);
        ~TroopFactory();
        Entity* makeUnit();
};