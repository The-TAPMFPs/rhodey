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

}

void ResearchAndDevelopment::developEconomy(){

}

void ResearchAndDevelopment::research(){

}

void ResearchAndDevelopment::setCountry(Country* country){
    this->country = country;
}