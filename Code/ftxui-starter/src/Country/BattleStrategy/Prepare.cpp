#include "Prepare.h"

Prepare::Prepare(Map* map) : BattleStrategy(map){}

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

void Prepare::doStrategy(Country* country){
    // take action of lowest between trrop and vehicle count
    Logger::log("Do the prepare strategy");
}

void Prepare::setNameNumCont(std::string name, int num, Country *con){
    _name = name;
    _num = num;
    _con = con;
}

void Prepare::setVehicle(std::string name, int num, VEHICLE_TYPE veh, Country * con){
    _name = name;
    _num = num;
    _veh = veh;
    _con = con;
}

void Prepare::recruitTroops(){
    // uf = new TroopFactory(_name, _num, _con);
    // uf->makeUnit();
    // delete uf;
}

void Prepare::buildVehicles(){
    // vf = new VehicleFactory(_name, _num, _veh, _con);
    // vf->makeUnit();
    // delete vf;
}

void Prepare::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Prepare::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}

