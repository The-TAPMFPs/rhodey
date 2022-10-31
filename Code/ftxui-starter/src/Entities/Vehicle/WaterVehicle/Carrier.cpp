#include "Carrier.h"

Carrier::Carrier(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    WaterVehicle(name, numberOfTroops, 10000, 1000, weapons) {
	this->terrianHandling = 32;
	this->capacity = 3000;
    };
