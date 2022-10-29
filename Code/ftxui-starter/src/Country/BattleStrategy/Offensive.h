#pragma once
#include "BattleStrategy.h"

enum _off {red, att};

class Offensive : public BattleStrategy {
    private:
        _off off;
    public:
        Offensive(_off off);
        void warAlgorithm() override;
        void redistributeTroops();
        void attack();
};