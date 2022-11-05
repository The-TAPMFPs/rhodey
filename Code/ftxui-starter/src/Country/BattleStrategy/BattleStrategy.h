//A BattleStrategy effectively represents a type of turn that a Country can make
//The chosen strategy for each Country is decided within the Coutry based on its statistics at that time
#pragma once
#include <string>
#include "Factories/TroopFactory.h"
#include "Factories/VehicleFactory.h"
#include "../Country.h"

class BattleStrategy {
    protected:
        TroopFactory * uf;
        VehicleFactory * vf;
        Country * _con;
    public:
        virtual void warAlgorithm() = 0;
        virtual ~BattleStrategy();
};