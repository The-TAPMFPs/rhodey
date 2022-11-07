#include "CargoPlane.h"
CargoPlane::CargoPlane(string name, int numberOfTroops,
	vector<Weapon *> * weapons, Country * country) : AirVehicle(name,
	    numberOfTroops, 100, 0, weapons, country, "CargoPlane") {
	this->terrianHandling = 50;
	this->capacity = 30;
    };

Entity * CargoPlane::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new CargoPlane(name, numberOfTroops, weapon, this->country);
}
