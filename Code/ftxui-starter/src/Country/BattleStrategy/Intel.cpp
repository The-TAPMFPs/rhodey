#include "Intel.h"

Intel::Intel() : BattleStrategy(NULL) {  }

Intel::Intel(Map* map) : BattleStrategy(map){}

void Intel::doStrategy(Country* country){
    int enemyToSPyOnIndex = uuid::randomInt(0, country->allies->getEnemyAlliance()->numCountries() - 1);
    Country* enemyToSpyOn = country->allies->getEnemyAlliance()->getIthCountry(enemyToSPyOnIndex);

    std::vector<std::pair<Country*, double>>* countriesBeingSpiedOn = country->getCountriesBeingSpiedOn();
    bool alreadyBeingSpiedOn = false;
    for(int i = 0; i < countriesBeingSpiedOn->size() && !alreadyBeingSpiedOn; i++){
        if((*countriesBeingSpiedOn)[i].first == enemyToSpyOn){
            alreadyBeingSpiedOn = true;
        }
    }

    if(!alreadyBeingSpiedOn){
        country->spyOnCountry(enemyToSpyOn);
        country->setNumSpies(country->getNumSpies() + 1);
        countriesBeingSpiedOn->push_back(std::pair<Country*, double>(enemyToSpyOn, 0));
        Logger::log(country->name + " is now spying on :" + enemyToSpyOn->name + "\n");
        // country->spyOnCountry(enemyToSpyOn);
        // countriesBeingSpiedOn->push_back(std::pair<Country*, double>(enemyToSpyOn, 0));
        // Logger::log(country->name + " is now spying on :" + enemyToSpyOn->name);
    } 
}

void Intel::setMyCountry(Country* myCountry){
    this->myCountry = myCountry;
}

void Intel::setEnemyCountry(Country* enemyCountry){
    this->enemyCountry = enemyCountry;

}