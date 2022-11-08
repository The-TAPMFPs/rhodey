#pragma once
#include <vector>

class Country;

class Observable {
 private:
  std::vector<Country*> countriesThatAreSpyingOnMe;
 public:
    void spyOnCountry(Country* country);
    void alertSpyCountries();
    void recieveIntel(Country* countryBeingSpiedOn);
};