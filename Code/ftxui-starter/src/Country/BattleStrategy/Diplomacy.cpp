#include "Diplomacy.h"

Diplomacy::Diplomacy(){
}

void Diplomacy::warAlgorithm(int dip){
    this->dip =(_dip) dip;

    switch(dip){
        case suDip:
            surrender();
            break;
        case ptDip:
            proposeTreaty();
            break;
    }
    return;
}

void Diplomacy::surrender(){
    //cout 
}

void Diplomacy::proposeTreaty(){
    
}

void Diplomacy::setMyCountry(Country* myCountry){
    this->myCountry = myCountry;
}

void Diplomacy::setEnemyCountry(Country* enemyCountry){
    this->enemyCountry = enemyCountry;
    std::string temp;
    Logger::log("");
}

void Diplomacy::proposeTreaty(){
    std::string temp;
    Logger::log("");
}