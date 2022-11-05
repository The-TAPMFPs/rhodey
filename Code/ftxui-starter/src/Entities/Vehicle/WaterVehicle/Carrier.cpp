#include "Carrier.h"

Carrier::Carrier(string name, int numberOfTroops, vector<Weapon *> * weapons,
	Country * country) : WaterVehicle(name, numberOfTroops, 1000, 90,
	    weapons, country) {
	this->terrianHandling = 32;
	this->capacity = 3000;
    };

Entity * Carrier::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Carrier(name, numberOfTroops, weapon, this->country);
}
