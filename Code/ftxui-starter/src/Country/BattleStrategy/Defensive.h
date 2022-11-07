#pragma once
#include "BattleStrategy.h"

// class BattleStrategy;

class Defensive : public BattleStrategy {
    protected:
        Region* friendlyRegion;
        Region* enemyRegion;
        std::string _name;
        int _num;
    public:
        Defensive(Map* map);
        void doStrategy(Country* country);
        void setNameNumCont(std::string name, int num, Country * con);
        void redistributeTroops();
        void recruitTroops();
        void setFriendlyRegion(Region* friendlyRegion);
        void setEnemyRegion(Region* enemyRegion);
};
