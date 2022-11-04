#include "Warship.h"
Warship::Warship(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    WaterVehicle(name, numberOfTroops, 10000, 2000, weapons) {
	this->terrianHandling = 32;
	this->capacity = 2000;
    };

Entity * Warship::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Warship(name, numberOfTroops, weapon);
}
