#include "Tank.h"
Tank::Tank(string name, int numberOfTroops, vector<Weapon *> * weapons, Country * country) :
    GroundVehicle(name, numberOfTroops, 500, 30, weapons, country, "Tank") {
	this->terrianHandling = 50;
	this->capacity = 5;
    };

Entity * Tank::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Tank(name, numberOfTroops, weapon, this->country);
}
