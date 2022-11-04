#include "Truck.h"
Truck::Truck(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    GroundVehicle(name, numberOfTroops, 100, 10, weapons) {
	this->terrianHandling = 32;
	this->capacity = 30;
    };


Entity * Truck::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Truck(name, numberOfTroops, weapon);
}
