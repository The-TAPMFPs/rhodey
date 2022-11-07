#include "Bomber.h"

Bomber::Bomber(string name, int numberOfTroops, vector<Weapon*>* weapons,
	Country * country) : AirVehicle(name, numberOfTroops, 100, 42, weapons,
	    country, "Bomber") {
	this->terrianHandling = 50;
	this->capacity = 30;
};
/**
 * \fn Entity* Bomber::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon)
 * \brief function that returns a new bomber 
 * 
 * \return the region at the specified coordin
 */
Entity * Bomber::splitType(string name, int numberOfTroops, vector<Weapon*> * weapon) {
    return new Bomber(name, numberOfTroops, weapon, this->country);
}
