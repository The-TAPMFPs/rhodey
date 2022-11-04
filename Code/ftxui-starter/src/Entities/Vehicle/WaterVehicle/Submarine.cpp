#include "Submarine.h"
Submarine::Submarine(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    WaterVehicle(name, numberOfTroops, 10000, 2000, weapons) {
	this->terrianHandling = 32;
	this->capacity = 30;
    };

Entity * Submarine::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Submarine(name, numberOfTroops, weapon);
}
