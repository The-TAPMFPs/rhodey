#include "ResearchAndDevelopment.h"

ResearchAndDevelopment::ResearchAndDevelopment(_rad rad){
    this->rad = rad;
}

void ResearchAndDevelopment::warAlgorithm(){
    switch(rad){
        case rt:
            researchTroops();
            break;
        case rv:
            researchVehicles();
            break;
        case rw:
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