#pragma once
#include "BattleStrategy.h"

// class BattleStrategy;

class Offensive : public BattleStrategy {
    private:
        Region* friendlyRegion;
        Region* enemyRegion;

    public:

        Offensive(Map* map);
        void doStrategy(Country* country);
        void redistributeTroops();
        void attack();
        void setFriendlyRegion(Region* friendlyRegion);
        void setEnemyRegion(Region* enemyRegion);

};
