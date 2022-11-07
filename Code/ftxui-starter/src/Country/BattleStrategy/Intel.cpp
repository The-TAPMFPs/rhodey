#include "Intel.h"

Intel::Intel(){
}

void Intel::doStrategy(Country* country){
    int enemyToSPyOnIndex = uuid::randomInt(0, country->allies->getEnemyAlliance()->numCountries());
    Country* enemyToSpyOn = country->allies->getEnemyAlliance()->getIthCountry(enemyToSPyOnIndex);

    enemyToSpyOn->spyOnCountry(country);
    Logger::log(country->name + " is now spying on :" + enemyToSpyOn->name);
}

void Intel::warAlgorithm(int intel){
    // dumb function
}

void Intel::setMyCountry(Country* myCountry){
    this->myCountry = myCountry;
}

void Intel::setEnemyCountry(Country* enemyCountry){
    this->enemyCountry = enemyCountry;

}