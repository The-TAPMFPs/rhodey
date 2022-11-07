#pragma once
#include "BattleStrategy.h"

// class BattleStrategy;

enum _off {redOff, attOff};

class Offensive : public BattleStrategy {
    private:
        _off off;
        Region* friendlyRegion;
        Region* enemyRegion;

    public:

        Offensive();
        void doStrategy(Country* country);
        void warAlgorithm(int off);
        void redistributeTroops();
        void attack();
        void setFriendlyRegion(Region* friendlyRegion);
        void setEnemyRegion(Region* enemyRegion);

};
