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
	    case ENTITY_TYPE::TRUCK:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::TRUCK);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Truck(someName,numToMake,weapons,this->country);
		break;
	    case ENTITY_TYPE::TANK:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::TANK);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Tank(someName,numToMake,weapons,this->country);
		break;
	    case ENTITY_TYPE::CARRIER:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::CARRIER);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Carrier(someName,numToMake,weapons,this->country);
		break;
	    case ENTITY_TYPE::CARGOSHIP:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::CARGOSHIP);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new CargoShip(someName,numToMake,weapons,this->country);
		break;
	    case ENTITY_TYPE::WARSHIP:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::WARSHIP);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Warship(someName,numToMake,weapons,this->country);
		break;
	    case ENTITY_TYPE::SUBMARINE:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::SUBMARINE);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Submarine(someName,numToMake,weapons,this->country);
		break;
	    case ENTITY_TYPE::FIGHTERJET:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::FIGHTERJET);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Fighterjet(someName,numToMake,weapons,this->country);
		break;
	    case ENTITY_TYPE::BOMBER:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::BOMBER);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new Bomber(someName,numToMake,weapons,this->country);
		break;
	    case ENTITY_TYPE::CARGOPLANE:
		numToMake = this->numberToProduce();
		weapons = getWeapons(numToMake, ENTITY_TYPE::CARGOPLANE);
		someName = this->name + " " + this->incAndGetBatalionNumber();
		toReturn = (Entity *) new CargoPlane(someName,numToMake,weapons,this->country);
		break;
	}
    }
    this->ouputCreationFlair(*weapons,toReturn);
    this->country->getMap()->getOccupancyTable()->addEntity(toReturn, this->country->getCapital());
    return (toReturn);
}
