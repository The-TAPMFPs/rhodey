#pragma once

#include "UnitFactory.h"


enum WEAPON_TYPE {bazooka, sniper, sniper50, pistol, ar, smg};

class TroopFactory : public UnitFactory{
    private:
        WEAPON_TYPE currWeaponType;
    public:
        TroopFactory(std::string name, int hp, int num);
        ~TroopFactory();
        void setWeaponType(WEAPON_TYPE type);
        Entity* makeUnit();
};