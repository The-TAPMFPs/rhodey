#pragma once
#include "BattleStrategy.h"

// class BattleStrategy;

enum _rad {drRD, deRD, rRD};
class ResearchAndDevelopment : public BattleStrategy {
    private:
        _rad rad;
        Country* friendlyCountry;
    public:

        ResearchAndDevelopment(Map* map);
        void doStrategy(Country* country);
        void warAlgorithm(int rad);
        void developResources();
        void developEconomy();
        void research();
};
