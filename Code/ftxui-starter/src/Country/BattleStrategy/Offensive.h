#pragma once
#include "BattleStrategy.h"

class Offensive : public BattleStrategy {
    public:
        void warAlgorithm();
        void redistributeTroops();
        void recruitTroops();
        void attack();
        void makeAlliance();
        void spy();
};