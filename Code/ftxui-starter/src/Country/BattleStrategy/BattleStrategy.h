//A BattleStrategy effectively represents a type of turn that a Country can make
//The chosen strategy for each Country is decided within the Coutry based on its statistics at that time
#pragma once
#include <string>

class BattleStrategy {
    public:
        virtual void warAlgorithm() = 0;
        virtual ~BattleStrategy();
};