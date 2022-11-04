#include "Prepare.h"

Prepare::Prepare(_prep prep){
    this->prep = prep;
}

void Prepare::warAlgorithm(){
    switch(prep){
        case redP:
            redistributeTroops();
            break;
        case recP:
            recruitTroops();
            break;
        case bvP:
            buildVehicles();
            break;
        case bwP:
            buildWeapons();
            break;
    }
    return;
}

void Prepare::redistributeTroops(){

}

void Prepare::recruitTroops(){

}

void Prepare::buildVehicles(){

}

void Prepare::buildWeapons(){

}
