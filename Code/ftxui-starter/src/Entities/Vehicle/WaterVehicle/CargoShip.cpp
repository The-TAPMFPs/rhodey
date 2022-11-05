#include "CargoShip.h"
CargoShip::CargoShip(string name, int numberOfTroops,
	vector<Weapon *> * weapons, Country * country) : WaterVehicle(name,
	    numberOfTroops, 1000, 20, weapons, country) {
	this->terrianHandling = 32;
	this->capacity = 2000;
    };

Entity * CargoShip::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new CargoShip(name, numberOfTroops, weapon, this->country);
}
