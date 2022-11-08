#include "Tank.h"
Tank::Tank(string name, int numberOfTroops, vector<Weapon *> * weapons, Country * country) :
    GroundVehicle(name, numberOfTroops, 500, 30, weapons, country, "Tank") {
	this->terrianHandling = 50;
	this->capacity = 5;
    };

Entity * Tank::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Tank(name, numberOfTroops, weapon, this->country);
}


int Tank::weaknesses(int damage, Weapon & weapon) {
    int total = GroundVehicle::weaknesses(damage, weapon);
    if (weapon.getType() == SMALL_ARMS) {
	total = 0;
    }
    if (weapon.getType() == HIGH_CAL) {
	total = 0;
    }
    return total;
}
