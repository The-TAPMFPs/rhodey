#include "TroopFactory.h"
#include "Entities/Troop.h"
#include "WeaponTemplate/Weapon.h"
#include <vector>
#include <string>

TroopFactory::TroopFactory(std::string name, int num){
    _name = name;
    _num = num;
    vector<Weapon*> w1 {}
}

TroopFactory::~TroopFactory(){}

Entity* TroopFactory::makeUnit(){
    
}


