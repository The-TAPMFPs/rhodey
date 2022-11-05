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

void Prepare::recruitTroops(){

}

void Prepare::buildVehicles(){

}

void Prepare::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Prepare::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}

