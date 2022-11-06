#include "ResearchAndDevelopment.h"

ResearchAndDevelopment::ResearchAndDevelopment(){
    
}

void ResearchAndDevelopment::warAlgorithm(int rad){
    this->rad =(_rad) rad;
    switch(rad){
        case drRD:
            developResources();
            break;
        case deRD:
            developEconomy();
            break;
        case rRD:
            research();
            break;
    }
    return;
}

void ResearchAndDevelopment::developResources(){
    srand((unsigned)time(NULL));
    double change = (((double) rand() / RAND_MAX) * 0.10-0.01) + 0.01;
    this->friendlyCountry->setResources(this->friendlyCountry->getResources() + change);
    Logger::log("Resources increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName());

}

void ResearchAndDevelopment::developEconomy(){
    srand((unsigned)time(NULL));
    double change = (((double) rand() / RAND_MAX) * 0.10-0.01) + 0.01;
    this->friendlyCountry->setEconomy(this->friendlyCountry->getEconomy() + change);
    Logger::log("Economy increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName());

}

void ResearchAndDevelopment::research(){
    srand((unsigned)time(NULL));
    double change = (((double) rand() / RAND_MAX) * 0.10-0.01) + 0.01;
    this->friendlyCountry->setResearch(this->friendlyCountry->getResearch() + change);
    Logger::log("Research increased by " + std::to_string(change) + " for " + this->friendlyCountry->getName());

}

void ResearchAndDevelopment::setFriendlyCountry(Country* friendly){
    this->friendlyCountry = friendly;
}