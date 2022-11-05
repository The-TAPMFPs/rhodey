#include "Prepare.h"


Prepare::Prepare(_prep prep){
    this->prep = prep;
}

void Prepare::warAlgorithm(){
    switch(prep){
        case rec:
            recruitTroops();
            break;
        case bv:
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

