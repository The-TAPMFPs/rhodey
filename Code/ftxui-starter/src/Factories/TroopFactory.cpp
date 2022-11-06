#include "TroopFactory.h"
#include <sstream>


TroopFactory::TroopFactory(std::string name, int num, Country * con){
    _name = name;
    _num = num;
    _con = con;
    //level 1
    SMG* smg;
    Pistol* pis;
    //level 2
    AR* ar;
    Sniper* sni;
    //level 3
    DualBurette* db;
    Bazooka* baz;
    //level 4
    Sniper50* s50;
    AK47* ak;
    w1 =  new vector<Weapon *> {smg, pis};
    w2 = new vector<Weapon *> {ar, pis, sni};
    w3 = new vector<Weapon *> {ar, smg, db, baz};
    w4 = new vector<Weapon *> {ar, pis, sni, baz};
    w5 = new vector<Weapon *> {ar, db, s50, ak};
    w6 = new vector<Weapon *> {ak, db, baz, s50};
}

TroopFactory::~TroopFactory(){}

Entity* TroopFactory::makeUnit(){
    int i = rand() % 2 + 1;
    std::string temp;
    std::stringstream convert;
    Troop * e;
    if(_con->getResearch() < 0.2){
        e = new Troop(_name, _num, w1, _con);
	convert << _num << " troops with SMGs and Pistols were recruited.";
        temp = convert.str();
        Logger::log(temp);
    }
    else if(_con->getResearch() < 0.5){
        e = new Troop(_name, _num, w2, _con);
        convert << _num << " troops with ARs, Pistols and Snipers were recruited.";
        temp = convert.str();
        Logger::log(temp);
    }
    else if(_con->getResearch() < 0.8){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w3, _con);
                convert << _num << " troops with ARs, SMGs, Dual Burettes and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
            case 2:
                e = new Troop(_name, _num, w4, _con);
                convert << _num << " troops with ARs, SMGs, Snipers and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
        }
    }
    else if(_con->getResearch() <= 1){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w5, _con);
		convert << _num << " troops with ARs, Dual Burettes, Sniper50s and AK47s were recruited.";
                temp = convert.str();
                Logger::log(temp);
            case 2:
                e = new Troop(_name, _num, w6, _con);
                convert << _num << " troops with AK47s, Dual Burettes, Bazooka and Sniper50s were recruited.";
                temp = convert.str();
                Logger::log(temp);
        }
    }
    return e;
}


