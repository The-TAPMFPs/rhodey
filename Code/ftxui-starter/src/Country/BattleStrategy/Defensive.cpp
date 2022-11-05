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

void Defensive::redistributeTroops(){

}

void Defensive::recruitTroops(){

}

void Defensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Defensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}


