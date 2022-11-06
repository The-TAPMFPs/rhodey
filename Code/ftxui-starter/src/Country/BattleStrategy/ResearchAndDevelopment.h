#pragma once
#include "BattleStrategy.h"

enum _rad {drRD, deRD, rRD};
class ResearchAndDevelopment : public BattleStrategy {
    private:
        _rad rad;
        Country* friendlyCountry;
    public:
        
        ResearchAndDevelopment();
        void warAlgorithm(int rad);
        void developResources();
        void developEconomy();
        void research();
        void setFriendlyCountry(Country* friendly);
};