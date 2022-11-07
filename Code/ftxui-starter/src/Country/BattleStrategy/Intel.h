#pragma once
#include "BattleStrategy.h"
#include "../../logger.h"
#include "../Country.h"
#include "../Observable.h"
#include <string>

class Observable;

class Intel : public BattleStrategy {
    private:
        Country* myCountry;
        Country* enemyCountry;

    public:
        Intel();
        void doStrategy(Country* country);
        void warAlgorithm(int intel);
        void setMyCountry(Country* myCountry);
        void setEnemyCountry(Country* enemyCountry);

};
