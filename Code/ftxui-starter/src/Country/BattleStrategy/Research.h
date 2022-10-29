#pragma once
#include "BattleStrategy.h"

class Research : public BattleStrategy {
    public:
        void warAlgorithm();
        void ResearchAndDevelop();
        void buildVehicles();
        void buildWeapons();
        void spy();
};