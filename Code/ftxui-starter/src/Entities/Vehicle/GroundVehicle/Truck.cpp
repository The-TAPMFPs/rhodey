#include "Truck.h"
Truck::Truck(string name, int numberOfTroops, vector<Weapon *> * weapons,
	Country * country) : GroundVehicle(name, numberOfTroops, 100, 10,
	    weapons, country) {
	this->terrianHandling = 32;
	this->capacity = 30;
    };


Entity * Truck::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Truck(name, numberOfTroops, weapon, this->country);
}
