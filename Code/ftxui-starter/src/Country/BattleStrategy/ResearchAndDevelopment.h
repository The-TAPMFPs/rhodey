#pragma once
#include "BattleStrategy.h"

enum _rad {drRD, deRD, rRD};
class ResearchAndDevelopment : public BattleStrategy {
    private:
        _rad rad;
        Country* country;
    public:
        
        ResearchAndDevelopment();
        void warAlgorithm(int rad);
        void developResources();
        void developEconomy();
        void research();
        void setCountry(Country* country);
};