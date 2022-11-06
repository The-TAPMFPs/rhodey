//A BattleStrategy effectively represents a type of turn that a Country can make
//The chosen strategy for each Country is decided within the Coutry based on its statistics at that time
#pragma once
#include <string>
#include "../../MapRegions/Region.h"
// #include "../Country.h"
#include "../../Factories/TroopFactory.h"
#include "../../Factories/VehicleFactory.h"
//#include "../Country.h"

class Region;

class BattleStrategy {
    protected:
        TroopFactory * uf;
        VehicleFactory * vf;
        Country * _con;
    public:
        virtual void warAlgorithm(int enumInput) = 0;
        virtual ~BattleStrategy();
};