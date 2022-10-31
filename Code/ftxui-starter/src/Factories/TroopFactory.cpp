#include "TroopFactory.h"
#include "Entities/Troop/Soldier.h"

TroopFactory::TroopFactory(std::string name, int hp, int num){
    _name = name;
    _hp = hp;
    _num = num
}

TroopFactory::~TroopFactory(){}

void TroopFactory::setWeaponType(WEAPON_TYPE type){
    currWeaponType = type;
}

Entity* TroopFactory::makeUnit(){
    switch(currWeaponType){
        case bazooka:
            Troop t = new Troop();
            return t;
        case sniper:
            Troop t = new Troop();
            return t;
        case sniper50:
            Troop t = new Troop();
            return t;
        case pistol:
            Troop t = new Troop();
            return t;
        case ar: 
            Troop t = new Troop();
            return t;
        case smg:
    }
}


