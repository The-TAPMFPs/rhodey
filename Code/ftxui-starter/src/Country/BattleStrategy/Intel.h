#pragma once
#include "BattleStrategy.h"
#include "../../logger.h"
#include "../Country.h"
#include <string>

class Intel : public BattleStrategy {
    private:
        Country* myCountry;
        Country* enemyCountry;

    public:
        Intel();
        Intel(Map* map);
        void doStrategy(Country* country);
        void setMyCountry(Country* myCountry);
        void setEnemyCountry(Country* enemyCountry);

};
