#include "CargoPlane.h"
CargoPlane::CargoPlane(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    AirVehicle(name, numberOfTroops, 1000, 70, weapons) {
	this->terrianHandling = 50;
	this->capacity = 30;
    };
