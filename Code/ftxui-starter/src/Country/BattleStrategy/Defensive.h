#pragma once
#include "BattleStrategy.h"


enum _def {redDef, recDef};
class Defensive : public BattleStrategy {
    private:
        _def def;
        Region* friendlyRegion;
        Region* enemyRegion;
    public:
        Defensive();
        void warAlgorithm(int def);
        std::string _name;
        int _num;
        void setNameAndNum(std::string name, int num);
        void setDef(_def def);
        void redistributeTroops();
        void recruitTroops();
        void setFriendlyRegion(Region* friendlyRegion);
        void setEnemyRegion(Region* enemyRegion);
};