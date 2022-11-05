#pragma once
#include "BattleStrategy.h"

enum _prep {rec, bv, bw};

class Prepare : public BattleStrategy {
    private:
        _prep prep;
        std::string _name;
        int _num;
        VEHICLE_TYPE _veh;
    public:
        Prepare(_prep prep);
        void warAlgorithm() override;
        void setNameAndNum(std::string name, int num);
        void setVehicle(std::string name, int num, VEHICLE_TYPE veh);
        void recruitTroops();
        void buildVehicles();
};