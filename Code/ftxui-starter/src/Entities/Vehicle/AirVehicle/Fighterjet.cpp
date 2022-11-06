#include "Fighterjet.h"
Fighterjet::Fighterjet(string name, int numberOfTroops,
	vector<Weapon *> * weapons, Country * country) : AirVehicle(name,
	    numberOfTroops, 200, 30, weapons, country) {
	this->terrianHandling = 100;
	this->capacity = 0;
    };

Entity * Fighterjet::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Fighterjet(name, numberOfTroops, weapon, this->country);
}
