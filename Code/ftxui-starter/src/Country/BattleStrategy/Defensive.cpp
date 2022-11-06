#include "Defensive.h"

Defensive::Defensive(){
    
}

void Defensive::warAlgorithm(int def){
    this->def =(_def) def;

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

void Defensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Defensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}


