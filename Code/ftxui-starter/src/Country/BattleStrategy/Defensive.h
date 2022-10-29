#pragma once
#include "BattleStrategy.h"

class Defensive : public BattleStrategy {
    public:
        void warAlgorithm();
        void redistributeTroos();
        void recruitTroops();
        void defend();
        void makeAlliance();
        void endAlliance();
};