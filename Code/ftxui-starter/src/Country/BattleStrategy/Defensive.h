#pragma once
#include "BattleStrategy.h"


enum _def {redDef, recDef};
class Defensive : public BattleStrategy {
    protected:
        _def def;
        Region* friendlyRegion;
        Region* enemyRegion;
        std::string _name;
        int _num;
    public:
        Defensive();
        void warAlgorithm(int def);
        void setNameNumCont(std::string name, int num, Country * con);
        void setDef(_def def);
        void redistributeTroops();
        void recruitTroops();
        void setFriendlyRegion(Region* friendlyRegion);
        void setEnemyRegion(Region* enemyRegion);
};