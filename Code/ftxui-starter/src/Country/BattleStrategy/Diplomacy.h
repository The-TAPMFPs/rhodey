#pragma once
#include "BattleStrategy.h"
#include "../Country.h"
#include "../../logger.h"
#include <string>

enum _dip {suDip, ptDip};
class Diplomacy : public BattleStrategy {
    private:
        _dip dip;
        Country* myCountry;
        Country* enemyCountry;

    public:
        Diplomacy();
        void warAlgorithm(int dip);
        void surrender();
        void proposeTreaty();
        void setMyCountry(Country* myCountry);
        void setEnemyCountry(Country* enemyCountry);

};
