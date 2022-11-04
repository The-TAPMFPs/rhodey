#include "Defensive.h"

Defensive::Defensive(_def def){
    this->def = def;
}

void Defensive::warAlgorithm(){
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


