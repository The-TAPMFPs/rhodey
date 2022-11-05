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
            e = new Troop(_name, _num, w1);//cout "_num troops with AR's, Sniper's and Sniper50's were recruited"
            return e;                      //Do this for each case corresponding to the weapons that they were given
        case 2: 
            e = new Troop(_name, _num, w2);
            return e;
        case 3:
            e = new Troop(_name, _num, w3);
            return e;
        case 4:
            e = new Troop(_name, _num, w4);
            return e;
        case 5:
            e = new Troop(_name, _num, w5);
            return e;
    }
}


