#include "Defensive.h"

Defensive::Defensive(_def def){
    this->def = def;
}

void Defensive::warAlgorithm(){
    switch(def){
        case red:
            redistributeTroops();
            break;
        case rec:
            recruitTroops();
            break;
    }
    return;
}

void Defensive::redistributeTroops(){

}

void Defensive::recruitTroops(){

}


