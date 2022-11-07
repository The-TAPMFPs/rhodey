#include "Defensive.h"

Defensive::Defensive(Map* map) : BattleStrategy(map){}

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

void Defensive::doStrategy(Country* country){
    // if there is a non contesting region, move those troops to a contesting
      // region if no contesting region then recruit this->strategy = new
      // Defensive();
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
    OccupancyTable* occTable = map->getOccupancyTable();
    occTable->moveEntity(occTable->getEntities(friendlyRegion), enemyRegion);
    delete occTable;
    
}

void Defensive::recruitTroops(){
    // uf = new TroopFactory(_name, _num, _con);
    // uf->makeUnit();
    // delete uf;
}

void Defensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Defensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}


