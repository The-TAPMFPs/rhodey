#include "VehicleFactory.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "../Country/Country.h"
#include "../MapRegions/Map.h"

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
 : UnitFactory(name, num, con)
{
  _name = name;
  _num = num;
  _con = con;
  w1 = new vector<Weapon*> {}; /**<Vector which contains a set of references to weapon objects>*/
  w2 = new vector<Weapon*> {new Mg160(), new Cannon()}; /**<Vector which contains a set of references to weapon objects>*/
  w3 = new vector<Weapon*> {new Mg160(), new Cannon(), new Missile()}; /**<Vector which contains a set of references to weapon objects>*/
  w4 = new vector<Weapon*> {new Torpedo(), new Missile()}; /**<Vector which contains a set of references to weapon objects>*/
  w5 = new vector<Weapon*> {new Mg160()}; /**<Vector which contains a set of references to weapon objects>*/
  w6 = new vector<Weapon*> {new Bomb(), new Mg160()}; /**<Vector which contains a set of references to weapon objects>*/
}

/**
 * @fn ~VehicleFactory()
 * @brief The Destructor of the VehicleFactory class.
 */
VehicleFactory::~VehicleFactory() {
    for (int count = 0; count < w1->size(); count) {
	delete w1->at(w1->size()-1);
	w1->pop_back();
    }
    delete w1;

    for (int count = 0; count < w2->size(); count) {
	delete w2->at(w2->size()-1);
	w2->pop_back();
    }
    delete w2;
    for (int count = 0; count < w3->size(); count) {
	delete w3->at(w3->size()-1);
	w3->pop_back();
    }
    delete w4;
    for (int count = 0; count < w4->size(); count) {
	delete w4->at(w4->size()-1);
	w4->pop_back();
    }
    delete w4;
    for (int count = 0; count < w5->size(); count) {
	delete w5->at(w5->size()-1);
	w5->pop_back();
    }
    delete w5;
    for (int count = 0; count < w6->size(); count) {
	delete w6->at(w6->size()-1);
	w6->pop_back();
    }
    delete w6;
}

/**
 * @fn Entity* makeUnit()
 * @brief Makes the specific units based on chance and research level
 *        and returns a reference to the new Entity that has been made.
 */

Entity* VehicleFactory::makeUnit() {
  std::string temp; /**<A string to hold the message that the Vehicles were made.>*/
  std::stringstream convert; /**<A stringstream to concentate the intital message.>*/
  switch (currVehicleType) {
    case truck:
      e = (Entity*)new Truck(_name, _num, w1, _con);
      w1 = new vector<Weapon*> {};
      convert << _num << " trucks were made.";
      temp = convert.str();
      Logger::log(temp);
      w1 = new vector<Weapon*> {};
      break;
    case tank:
      e = (Entity*)new Tank(_name, _num, w2, _con);
      w2 = new vector<Weapon*> {new Mg160(), new Cannon()};
      convert << _num << " tanks were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
    case carrier:
      e = (Entity*)new Carrier(_name, _num, w2, _con);
      w2 = new vector<Weapon*> {new Mg160(), new TankCannon()};
      convert << _num << " carriers were made.";
      temp = convert.str();
      Logger::log(temp);
      w4 = new vector<Weapon*> {new Torpedo(), new Missile()};
      break;
    case cargoship:
      e = (Entity*)new CargoShip(_name, _num, w1, _con);
       w1 = new vector<Weapon*> {};
      convert << _num << " cargoships were made.";
        temp = convert.str();
      Logger::log(temp);
      w1 = new vector<Weapon*> {};
      break;
    case warship:
      e = (Entity*)new Warship(_name, _num, w3, _con);
      w3 = new vector<Weapon*> {new Mg160(), new Cannon(), new Missile()};
      convert << _num << " warships were made.";
        temp = convert.str();
      Logger::log(temp);
      w3 = new vector<Weapon*> {new Mg160(), new Cannon(), new Missile()};
      break;
    case submarine:
      e = (Entity*)new Submarine(_name, _num, w4, _con);
      w4 = new vector<Weapon*> {new Torpedo(), new Missile()};
      convert << _num << " submarines were made.";
        temp = convert.str();
      Logger::log(temp);
      w4 = new vector<Weapon*> {new Torpedo(), new Missile()};
    case fighterjet:
      e = (Entity*)new Fighterjet(_name, _num, w6, _con);
      convert << _num << " fighterjets were made.";
        temp = convert.str();
      Logger::log(temp);
      w6 = new vector<Weapon*> {new Bomb(), new Mg160()};
      break;
    case bomber:
      e = (Entity*)new Bomber(_name, _num, w6, _con);
      w6 = new vector<Weapon*> {new Bomb(), new Mg160()};
      convert << _num << " bombers were made.";
        temp = convert.str();
      Logger::log(temp);
      w6 = new vector<Weapon*> {new Bomb(), new Mg160()};
      break;
    case cargoplane:
      e = (Entity*)new CargoPlane(_name, _num, w1, _con);
       w1 = new vector<Weapon*> {};
      convert << _num << " cargo planes were made.";
        temp = convert.str();
      Logger::log(temp);
      w1 = new vector<Weapon*> {};
      break;
  }
  this->_con->getMap()->getOccupancyTable()->addEntity(e, this->_con->getCapital());
  return e;
}
