#include "TroopFactory.h"
#include <sstream>
#include "Entities/WeaponTemplateMethod/Weapon.h"


TroopFactory::TroopFactory(std::string name, int num, Country * con){
    _name = name;
    _num = num;
    _con = con;
    //level 1
    w1 =  new vector<Weapon *> {new SMG(), new Pistol()};
    //level 2
    w2 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper()};
    //level 3
    w3 = new vector<Weapon *> {new AR(), new SMG(), new DualBurette(), new Bazooka()};
    //level 4
    w4 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper(), new Bazooka()};
    w5 = new vector<Weapon *> {new AR(), new DualBurette(), new Sniper50(), new AK47()};
    w6 = new vector<Weapon *> {new AK47(), new DualBurette(), new Sniper50(), new Bazooka()};
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
	w1 =  new vector<Weapon *> {new SMG(), new Pistol()};
    }
    else if(_con->getResearch() < 0.5){
        e = new Troop(_name, _num, w2, _con);
        convert << _num << " troops with ARs, Pistols and Snipers were recruited.";
        temp = convert.str();
        Logger::log(temp);
	w2 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper()};
    }
    else if(_con->getResearch() < 0.8){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w3, _con);
                convert << _num << " troops with ARs, SMGs, Dual Burettes and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
		w3 = new vector<Weapon *> {new AR(), new SMG(), new DualBurette(), new Bazooka()};
            case 2:
                e = new Troop(_name, _num, w4, _con);
                convert << _num << " troops with ARs, SMGs, Snipers and Bazookas were recruited.";
                temp = convert.str();
                Logger::log(temp);
		w4 = new vector<Weapon *> {new AR(), new Pistol(), new Sniper(), new Bazooka()};
        }
    }
    else if(_con->getResearch() <= 1){
        switch(i){
            case 1:
                e = new Troop(_name, _num, w5, _con);
		convert << _num << " troops with ARs, Dual Burettes, Sniper50s and AK47s were recruited.";
                temp = convert.str();
                Logger::log(temp);
		w5 = new vector<Weapon *> {new AR(), new DualBurette(), new Sniper50(), new AK47()};
            case 2:
                e = new Troop(_name, _num, w6, _con);
                convert << _num << " troops with AK47s, Dual Burettes, Bazooka and Sniper50s were recruited.";
                temp = convert.str();
                Logger::log(temp);
		w6 = new vector<Weapon *> {new AK47(), new DualBurette(), new Sniper50(), new Bazooka()};
        }
    }
    return e;
}


