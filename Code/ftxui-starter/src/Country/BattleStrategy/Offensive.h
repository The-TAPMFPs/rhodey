#pragma once
#include "BattleStrategy.h"

enum _off {red, rec, att, spy};

class Offensive : public BattleStrategy {
    private:
        _off off;
    public:
        Offensive(_off off);
        void warAlgorithm() override;
        void redistributeTroops();
        void recruitTroops();
        void attack();
};