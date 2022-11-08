#pragma once
#include "BattleStrategy.h"

// class BattleStrategy;

class ResearchAndDevelopment : public BattleStrategy {
    private:
        Country* friendlyCountry;
    public:

        ResearchAndDevelopment(Map* map);
        void doStrategy(Country* country);
        // void developResources();
        // void developEconomy();
        // void research();
};
