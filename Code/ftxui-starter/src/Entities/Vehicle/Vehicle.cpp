#include "Vehicle.h"

Vehicle::Vehicle(string name, int numberOfTroops, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country) : Entity(name,
	    "Vehicle", HP, Damage, weapon, country) {
    this->HPScalling = this->HP;
    this->HP = numberOfTroops * this->HP;
};

int Vehicle::getCarryingCapacity() {
    return this->capacity;
}

int Vehicle::getTerrainHandling() {
    return this->terrianHandling;
}
