#pragma once
#include "BattleStrategy.h"

enum _def {redDef, recDef};
class Defensive : public BattleStrategy {
    private:
        _def def;
    public:
        Defensive(_def def);
        void warAlgorithm() override;
        void redistributeTroops();
        void recruitTroops();
};