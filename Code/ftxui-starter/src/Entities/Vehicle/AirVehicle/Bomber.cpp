#include "Bomber.h"
/**
 *\fn void Bomber::Bomber(string name, int numberOfTroops, vector<Weapon*>* weapons)
 * \brief constructor that sets terrainHandling and capacity
 * 
 * 
*/
Bomber::Bomber(string name, int numberOfTroops, vector<Weapon*>* weapons) :
    AirVehicle(name, numberOfTroops, 1000, 70, weapons) {
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
    return new Bomber(name, numberOfTroops, weapon);
}
