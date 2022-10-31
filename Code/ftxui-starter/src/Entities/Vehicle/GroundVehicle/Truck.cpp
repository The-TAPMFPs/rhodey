#include "Truck.h"
Truck::Truck(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    GroundVehicle(name, numberOfTroops, 250, 1, weapons) {
	this->terrianHandling = 32;
	this->capacity = 30;
    };
