#pragma once
#include "BattleStrategy.h"
#include "../Country.h"
#include "../../Factories/VehicleFactory.h"
#include "../../Factories/TroopFactory.h"

// class BattleStrategy;

class Prepare : public BattleStrategy {
    private:
        Region* friendlyRegion;
        Region* enemyRegion;
        std::string _name;
        int _num;
        VEHICLE_TYPE _veh;
    public:
        Prepare(Map* map);
        void doStrategy(Country* country);
        // void buildVehicles();
        // void recruitTroops();
        // void setFriendlyRegion(Region* friendlyRegion);
        // void setEnemyRegion(Region* enemyRegion);
        // void setNameNumCont(std::string name, int num, Country * con);
        // void setVehicle(std::string name, int num, VEHICLE_TYPE veh, Country * con);
};
