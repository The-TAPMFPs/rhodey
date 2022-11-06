#pragma once

#include "UnitFactory.h"

class TroopFactory : public UnitFactory{
    public:
        TroopFactory(std::string name, int num);
        ~TroopFactory();
        Entity* makeUnit();
};