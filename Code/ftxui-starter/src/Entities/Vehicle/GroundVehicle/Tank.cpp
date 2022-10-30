#include "Tank.h"
Tank::Tank(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    GroundVehicle(name, numberOfTroops, 1500, 100, weapons) {
	this->terrianHandling = 50;
	this->capacity = 5;
    };
