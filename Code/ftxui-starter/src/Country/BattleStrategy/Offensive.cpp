#include "Offensive.h"

Offensive::Offensive(){
    
}

void Offensive::warAlgorithm(int off){
    this->off =(_off) off;
    switch(off){
        case redOff:
            redistributeTroops();
            break;
        case attOff:
            attack();
            break;
    }
    return;
}

void Offensive::doStrategy(Country* country){
    Logger::log("Do the offensive strategy");
}

void Offensive::redistributeTroops(){

}

void Offensive::attack(){

}

void Offensive::setFriendlyRegion(Region* friendlyRegion){
    this->friendlyRegion = friendlyRegion;
}

void Offensive::setEnemyRegion(Region* enemyRegion){
    this->enemyRegion = enemyRegion;
}
