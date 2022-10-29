#pragma once
#include "BattleStrategy.h"

class Prepare : public BattleStrategy {
    public:
        void warAlgorithm();
        void redistributeTroops();
        void recruitTroops();
        void buildVehicles();
        void buildWeapons();
        void makeAlliance();
        void endAlliance();
        void spy();
};