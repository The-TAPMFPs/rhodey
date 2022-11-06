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

void Diplomacy::setMyCountry(Country* myCountry){
    this->myCountry = myCountry;
}

void Diplomacy::setEnemyCountry(Country* enemyCountry){
    this->enemyCountry = enemyCountry;

}

void Diplomacy::proposeTreaty(){
    std::string temp;
    temp = myCountry->getName() + " proposed a treaty with " + enemyCountry->getName();
    Logger::log(temp);
    //Have a treaty function in the country
}

void Diplomacy::surrender(){
    std::string temp;
    temp = myCountry->getName() + " surrended to " + enemyCountry->getName();
    Logger::log(temp);
    //Have a surrender function in the country
}
