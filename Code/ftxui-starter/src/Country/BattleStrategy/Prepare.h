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
};