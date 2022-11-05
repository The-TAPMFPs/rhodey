#pragma once
#include "BattleStrategy.h"

enum _def {redDef, recDef};
class Defensive : public BattleStrategy {
    private:
        _def def;
        std::string _name;
        int _num;
    public:
        Defensive(Country * con);
        void setNameAndNum(std::string name, int num);
        void setDef(_def def);
        void warAlgorithm() override;
        void redistributeTroops();
        void recruitTroops();
};