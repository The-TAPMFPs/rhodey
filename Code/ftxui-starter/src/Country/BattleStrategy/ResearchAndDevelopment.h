#pragma once
#include "BattleStrategy.h"

enum _rad {rtRD, rvRD, rwRD};
class ResearchAndDevelopment : public BattleStrategy {
    private:
        _rad rad;
    public:
        ResearchAndDevelopment(_rad rad);
        void warAlgorithm() override;
        void researchTroops();
        void researchVehicles();
        void researchWeapons();
};