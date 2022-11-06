#include "Warship.h"
Warship::Warship(string name, int numberOfTroops, vector<Weapon *> * weapons,
	Country * country) : WaterVehicle(name, numberOfTroops, 1000, 100,
	    weapons, country, "Warship") {
	this->terrianHandling = 32;
	this->capacity = 2000;
    };

Entity * Warship::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Warship(name, numberOfTroops, weapon, this->country);
}
