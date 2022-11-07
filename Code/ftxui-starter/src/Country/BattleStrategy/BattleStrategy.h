//A BattleStrategy effectively represents a type of turn that a Country can make
//The chosen strategy for each Country is decided within the Coutry based on its statistics at that time
#pragma once
#include "../../MapRegions/Region.h"
#include "../../Factories/TroopFactory.h"
#include "../../Factories/VehicleFactory.h"
#include "../Country.h"
#include "../../logger.h"
#include "../../MapRegions/Map.h"

class Country;
class TroopFactory;
class VehicleFactory;

class BattleStrategy {
protected:
        TroopFactory * uf;
        VehicleFactory * vf;
        Country * _con;
        Country* friendlyCountry;
        Country* enemyCountry;
        Region* friendlyRegion;
        Region* enemyRegion;
public:
	BattleStrategy();
    virtual void doStrategy(Country* country) = 0;
    virtual void warAlgorithm(int enumInput) = 0;
    virtual void setFriendlyRegion(Region* friendlyRegion){}
    virtual void setEnemyRegion(Region* enemyRegion){}
    virtual void setEnemyCountry(Country* enemy){}
    virtual ~BattleStrategy();
};
