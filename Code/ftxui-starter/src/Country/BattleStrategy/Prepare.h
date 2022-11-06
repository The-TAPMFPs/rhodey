#pragma once
#include "BattleStrategy.h"

enum _prep {recP, bvP};

class Prepare : public BattleStrategy {
    
    private:
        _prep prep;
        Region* friendlyRegion;
        Region* enemyRegion;
    public:
        
        Prepare();
        void warAlgorithm(int prep);
        void buildVehicles();
        void recruitTroops();
        void setFriendlyRegion(Region* friendlyRegion);
        void setEnemyRegion(Region* enemyRegion);
        std::string _name;
        int _num;
        VEHICLE_TYPE _veh;
        void setNameAndNum(std::string name, int num);
        void setVehicle(std::string name, int num, VEHICLE_TYPE veh);
};