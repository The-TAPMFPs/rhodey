#include "Defensive.h"

Defensive::Defensive(_def def){
    this->def = def;
}

void Defensive::warAlgorithm(){
    switch(def){
        case red:
            redistributeTroops();
            break;
        case rec:
            recruitTroops();
            break;
    }
    return;
}

void Defensive::setNameAndNum(std::string name, int num){
    _name = name;
    _num = num;
}

void Defensive::redistributeTroops(){

}

void Defensive::recruitTroops(){
    uf = new TroopFactory(_name, _num);
    uf->makeUnit();
    delete uf;
}


