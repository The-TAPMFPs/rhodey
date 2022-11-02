#include "TroopFactory.h"
#include "Entities/Troop/Troop.h"
#include "WeaponTemplateMethod/Weapon.h"
#include <vector>
#include <cstdlib>

    
TroopFactory::TroopFactory(std::string name, int num){
    _name = name;
    _num = num;
    AR* ar;
    SMG* smg;
    Pistol* pis;
    Sniper* sni;
    Sniper50* s50;
    Bazooka* baz;
    w1 =  new vector<Weapon *> {ar, sni, s50};
    w2 = new vector<Weapon *> {smg, pis, baz};
    w3 = new vector<Weapon *> {ar, smg, pis};
    w4 = new vector<Weapon *> {ar, pis, baz};
    w5 = new vector<Weapon *> {smg, sni, baz};
}

TroopFactory::~TroopFactory(){}

Entity* TroopFactory::makeUnit(){
    int i = rand() % 5 + 1;
    switch(i){
        case 1:
            Troop* t1 = new Troop(_name, _num, w1);
            return t1;
        case 2:
            Troop* t2 = new Troop(_name, _num, w2);
            return t2;
        case 3:
            Troop* t3 = new Troop(_name, _num, w3);
            return t3;
        case 4:
            Troop* t4 = new Troop(_name, _num, w4);
            return t4;
        case 5:
            Troop* t5 = new Troop(_name, _num, w5);
            return t5;
    }
}


