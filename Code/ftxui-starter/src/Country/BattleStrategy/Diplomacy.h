#pragma once
#include "BattleStrategy.h"

enum _dip {su, pt};
class Diplomacy : public BattleStrategy {
    private:
        _dip dip;
    public:
        Diplomacy(_dip dip);
        void warAlgorithm() override;
        void surrender();
        void proposeTreaty();
};