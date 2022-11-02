#include "Fighterjet.h"
Fighterjet::Fighterjet(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    AirVehicle(name, numberOfTroops, 675, 100, weapons) {
	this->terrianHandling = 100;
	this->capacity = 0;
    };

Entity * Fighterjet::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Fighterjet(name, numberOfTroops, weapon);
}
