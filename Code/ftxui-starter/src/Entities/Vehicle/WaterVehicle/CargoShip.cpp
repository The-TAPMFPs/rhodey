#include "CargoShip.h"
CargoShip::CargoShip(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    WaterVehicle(name, numberOfTroops, 10500, 500, weapons) {
	this->terrianHandling = 32;
	this->capacity = 2000;
    };