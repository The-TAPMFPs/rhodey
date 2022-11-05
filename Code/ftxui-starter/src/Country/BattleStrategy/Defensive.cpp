#include "Defensive.h"

Defensive::Defensive(Country * con){
    _con = con;
}

void Defensive::warAlgorithm(){
    switch(def){
        case redDef:
            redistributeTroops();
            break;
        case recDef:
            recruitTroops();
            break;
    }
    return;
}

void Defensive::setNameAndNum(std::string name, int num){
    _name = name;
    _num = num;
}

void Defensive::setDef(_def def){
    this->def = def;
}

void Defensive::redistributeTroops(){

}

void Defensive::recruitTroops(){
    uf = new TroopFactory(_name, _num);
    uf->makeUnit();
    delete uf;
}


