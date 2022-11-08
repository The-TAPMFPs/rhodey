
#include "Vehicle.h"
/**
 * @file VehicelFactory.cpp
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 08 November 2022 
 */

/**
 * \fn Vehicle::Vehicle(string name, int numberOfTroops, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country, std::string type)
  * \brief vehicle constructor that creates and initializes new vehicles
  *@param name name of vehicle 
  *@param numberOfTroops number of troops  vehicle can have
  @param HP the health of a vehicle 
  @param Damage the damage a vehicle can do 
  @param weapon a vector of weapons that a vehicle can have 
  @param country the country the vehicle belongs to 
  @param type the type of vehicle - air/land/water
*/
Vehicle::Vehicle(string name, int numberOfTroops, int HP, int Damage,
	vector<Weapon*> * weapon, Country * country, std::string type) : Entity(name,
	    type, HP, Damage, weapon, country) {
    this->HPScalling = this->HP;
    this->HP = numberOfTroops * this->HP;
};
/**
 * \fn int Vehicle::getCarryingCapacity()
 * \brief function that fetches the capacity of a vehicle
 * \return function returns the capacity of a certain vehicle 
*/
int Vehicle::getCarryingCapacity() {
    return this->capacity*this->getAmount();
}
/**
 * \fn int Vehicle::getTerrainHandling()
 * \brief function that fetches the terrain of a vehicle
 * \return function returns the terrain of a certain vehicle 
*/
int Vehicle::getTerrainHandling() {
    return this->terrianHandling;
}
