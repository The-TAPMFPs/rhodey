#include "Fighterjet.h"
Fighterjet::Fighterjet(string name, int numberOfTroops, vector<Weapon *> * weapons) :
    AirVehicle(name, numberOfTroops, 675, 100, weapons) {
	this->terrianHandling = 100;
	this->capacity = 0;
    };
