#pragma once
#include "BattleStrategy.h"

// class BattleStrategy;

class Diplomacy : public BattleStrategy {
    private:
        Country* myCountry;
        Country* enemyCountry;

    public:
        Diplomacy(Map* map);
        void doStrategy(Country* country);
        void surrender();
        void proposeTreaty();
        void setMyCountry(Country* myCountry);
        void setEnemyCountry(Country* enemyCountry);

};
