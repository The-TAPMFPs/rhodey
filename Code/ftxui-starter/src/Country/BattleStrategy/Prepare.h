#pragma once
#include "BattleStrategy.h"

enum _prep {redP, recP, bvP, bwP};

class Prepare : public BattleStrategy {
    private:
        _prep prep;
    public:
        Prepare(_prep prep);
        void warAlgorithm() override;
        void redistributeTroops();
        void recruitTroops();
        void buildVehicles();
        void buildWeapons();
};