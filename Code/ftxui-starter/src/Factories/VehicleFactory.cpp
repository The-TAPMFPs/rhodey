#include "VehicleFactory.h"
#include "Entities/Vehicle/GroundVehicle/Truck.h"
#include "Entities/Vehicle/Vehicle.h"
#include "Entities/Vehicle/WaterVehicle/CargoShip.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "../Country/Country.h"
#include "../MapRegions/Map.h"
#include "Factories/UnitFactory.h"

/**
 * @file VehicelFactory.cpp
 * @brief Construct a new Vehicle Factory object
 * @author The TransactionAwarePersistenceManagerFactoryProxies
 * @date 06 November 2022
 */

/**
 * @fn TroopFactory (std::string name, int num, Country * con)
 * @brief The constructor of the TroopFactory class.
 *
 * @param name Troop Name
 * @param num Amount of Troops
 * @param type An enum of the types of vehicles
 * @param con Country of Troops
 */
VehicleFactory::VehicleFactory(std::string name, int num, Country * con)
 : UnitFactory(name, num, con) {
}

/**
 * @fn ~VehicleFactory()
 * @brief The Destructor of the VehicleFactory class.
 */
VehicleFactory::~VehicleFactory() {
}

/**
 * @fn Entity* makeUnit()
 * @brief Makes the specific units based on chance and research level
 *        and returns a reference to the new Entity that has been made.
 */

Entity* VehicleFactory::makeUnit() {
    Entity * toReturn = NULL;
    std::vector<Weapon *> * weapons;
    int numToMake = 0;
    std::string someName = "";
    while (toReturn == NULL) {
	ENTITY_TYPE currVehicleType = ENTITY_TYPE(uuid::randomInt(0, 8));
	switch (currVehicleType) {
	    case TRUCK:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake,TRUCK);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Truck(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	    case TANK:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake,TANK);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Tank(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	    case CARRIER:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake,CARRIER);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Carrier(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	    case CARGOSHIP:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, CARGOSHIP);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new CargoShip(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	    case WARSHIP:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, WARSHIP);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Warship(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	    case SUBMARINE:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, SUBMARINE);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Submarine(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	    case FIGHTERJET:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, FIGHTERJET);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Fighterjet(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	    case BOMBER:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, BOMBER);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Bomber(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	    case CARGOPLANE:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, CARGOPLANE);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new CargoPlane(someName,numToMake,weapons,this->country);
		this->ouputCreationFlair(*weapons);
		break;
	}
    }
    this->country->getMap()->getOccupancyTable()->addEntity(toReturn, this->country->getCapital());
    return (toReturn);
}
