#include "TroopFactory.h"
#include "Entities/Troop/Troop.h"
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
    std::string temp;
    switch(i){
        case 1:
            e = new Troop(_name, _num, w1);
            temp = _num + " troops with ARs, Snipers and Sniper50s were recruited.";
            Logger::log(temp);
            return e;                     
        case 2: 
            e = new Troop(_name, _num, w2);
            temp = _num + " troops with SMGs, Pistols and Bazookas were recruited.";
            Logger::log(temp);
            return e;
        case 3:
            e = new Troop(_name, _num, w3);
            temp = _num + " troops with ARs, SMGs and Pistols were recruited.";
            Logger::log(temp);
            return e;
        case 4:
            e = new Troop(_name, _num, w4);
            temp = _num + " troops with ARs, Pistols and Bazookas were recruited.";
            Logger::log(temp);
            return e;
        case 5:
            e = new Troop(_name, _num, w5);
            temp = _num + " troops with SMGs, Snipers and Bazookas were recruited.";
            Logger::log(temp);
            return e;
    }
}


