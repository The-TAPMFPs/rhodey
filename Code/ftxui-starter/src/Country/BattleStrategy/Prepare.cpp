#include "Prepare.h"

Prepare::Prepare(_prep prep){
    this->prep = prep;
}

void Prepare::warAlgorithm(){
    switch(prep){
        case red:
            redistributeTroops();
            break;
        case rec:
            recruitTroops();
            break;
        case bv:
            buildVehicles();
            break;
        case bw:
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
