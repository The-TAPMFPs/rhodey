#pragma once
#include "BattleStrategy.h"

enum _def {red, rec};
class Defensive : public BattleStrategy {
    private:
        _def def;
        std::string _name;
        int _num;
    public:
        Defensive(_def def);
        void setNameAndNum(std::string name, int num);
        void warAlgorithm() override;
        void redistributeTroops();
        void recruitTroops();
};