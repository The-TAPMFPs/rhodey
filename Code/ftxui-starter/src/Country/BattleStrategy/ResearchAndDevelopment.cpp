#include "ResearchAndDevelopment.h"

ResearchAndDevelopment::ResearchAndDevelopment(_rad rad){
    this->rad = rad;
}

void ResearchAndDevelopment::warAlgorithm(){
    switch(rad){
        case rtRD:
            researchTroops();
            break;
        case rvRD:
            researchVehicles();
            break;
        case rwRD:
            researchWeapons();
            break;
    }
    return;
}

void ResearchAndDevelopment::researchTroops(){

}

void ResearchAndDevelopment::researchVehicles(){

}

void ResearchAndDevelopment::researchWeapons(){

}