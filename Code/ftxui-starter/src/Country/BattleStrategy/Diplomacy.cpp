#include "Diplomacy.h"

Diplomacy::Diplomacy(Map* map) : BattleStrategy(map){}

void Diplomacy::doStrategy(Country* country){
    Logger::log("Do the diplomacy strategy");
}

void Diplomacy::setMyCountry(Country* myCountry){
    this->myCountry = myCountry;
}

void Diplomacy::setEnemyCountry(Country* enemyCountry){
    this->enemyCountry = enemyCountry;

}

void Diplomacy::proposeTreaty(){
    Logger::log(myCountry->getName() + " proposed a treaty with " + enemyCountry->getName());
    //Have a treaty function in the country
}

void Diplomacy::surrender(){
    std::string temp;
    temp = myCountry->getName() + " surrended to " + enemyCountry->getName();
    Logger::log(temp);
    //Have a surrender function in the country
}
