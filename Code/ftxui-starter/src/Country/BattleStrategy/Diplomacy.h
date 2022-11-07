#pragma once
#include "BattleStrategy.h"

// class BattleStrategy;

enum _dip {suDip, ptDip};
class Diplomacy : public BattleStrategy {
    private:
        _dip dip;
        Country* myCountry;
        Country* enemyCountry;

    public:
        Diplomacy(Map* map);
        void doStrategy(Country* country);
        void warAlgorithm(int dip);
        void surrender();
        void proposeTreaty();
        void setMyCountry(Country* myCountry);
        void setEnemyCountry(Country* enemyCountry);

};
