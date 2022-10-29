#pragma once
#include "BattleStrategy.h"

class Defensive : public BattleStrategy {
    public:
        void warAlgorithm();
        void surrender();
        void proposeTreaty();
};