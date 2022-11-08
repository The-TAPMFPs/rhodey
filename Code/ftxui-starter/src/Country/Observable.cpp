#include "Observable.h"
#include "Country.h"
#include "logger.h"
/**
 * \fn void Observable::spyOnCountry (Country* country)
 * \brief the passed in country will recieve intel from this country
 * 
 * \param country the country that will recive intel (the spy)
*/
void Observable::spyOnCountry(Country* country){
    countriesThatAreSpyingOnMe.push_back(country);
}

/**
 * \fn void Observable::alertSpyCountries ()
 * \brief gives intel to all the countries that are spying on this country
 * 
*/
void Observable::alertSpyCountries(){
    for(int i = 0; i < countriesThatAreSpyingOnMe.size(); i++){
        countriesThatAreSpyingOnMe[i]->recieveIntel((Country*)this);
    }
}


/**
 * \fn void Observable::recieveIntel (Country* countryBeingSpiedOn)
 * \brief recieves intel from the passed in country and increases our knowledge Stat
 * 
 * \param countryBeingSpiedOn the country that is beign spied on
*/
void Observable::recieveIntel(Country* countryBeingSpiedOn){
    Logger::log(((Country*)(this))->getName() + " Recieved intel from: " + countryBeingSpiedOn->getName());

    std::vector<std::pair<Country*, double>>* countriesBeingSpiedOn = ((Country*)(this))->getCountriesBeingSpiedOn();
    
    for(int i = 0; i < countriesBeingSpiedOn->size(); i++){
        if((*countriesBeingSpiedOn)[i].first == countryBeingSpiedOn){
            (*countriesBeingSpiedOn)[i].second += 0.1;
        }
    }
}