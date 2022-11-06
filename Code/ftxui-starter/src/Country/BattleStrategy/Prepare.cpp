#include "Prepare.h"

Prepare::Prepare(){
}

void Prepare::warAlgorithm(int prep){
    this->prep =(_prep) prep;
    switch(prep){
        case recP:
            recruitTroops();
            break;
        case bvP:
            buildVehicles();
            break;
    }
    return;
}

void Prepare::setNameAndNum(std::string name, int num){
    _name = name;
    _num = num;
}

void Prepare::setVehicle(std::string name, int num, VEHICLE_TYPE veh){
    _name = name;
    _num = num;
    _veh = veh;
}

void Prepare::recruitTroops(){
    uf = new TroopFactory(_name, _num);
    uf->makeUnit();
    delete uf;
}

void Prepare::buildVehicles(){
    vf = new VehicleFactory(_name, _num, _veh);
    vf->makeUnit();
    delete vf;
}

void Prepare::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Prepare::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}

