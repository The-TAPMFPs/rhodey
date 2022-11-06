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

void Defensive::setNameNumCont(std::string name, int num, Country * con){
    _name = name;
    _num = num;
    _con = con;
}

void Defensive::setDef(_def def){
    this->def = def;
}

void Defensive::redistributeTroops(){
    
}

void Defensive::recruitTroops(){
    uf = new TroopFactory(_name, _num, _con);
    uf->makeUnit();
    delete uf;
}

void Defensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Defensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}


