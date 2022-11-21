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
    w2 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_CANNON)}; /**<Vector which contains a set of references to weapon objects>*/

    w3 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_MG160), this->weapons->getWeapon(CLASS_MG160), this->weapons->getWeapon(CLASS_MISSILE)}; /**<Vector which contains a set of references to weapon objects>*/

    w4 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_TORPEDO), this->weapons->getWeapon(CLASS_MISSILE)}; /**<Vector which contains a set of references to weapon objects>*/

    w5 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_MG160)}; /**<Vector which contains a set of references to weapon objects>*/

    w6 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_BOMB), this->weapons->getWeapon(CLASS_MG160)}; /**<Vector which contains a set of references to weapon objects>*/

}

/**
 * @fn ~VehicleFactory()
 * @brief The Destructor of the VehicleFactory class.
 */
VehicleFactory::~VehicleFactory() {

    delete w1;


    delete w2;

    delete w3;

    delete w4;

    delete w5;

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
  VEHICLE_TYPE currVehicleType = VEHICLE_TYPE(uuid::randomInt(0, 8));
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
        w2 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_CANNON)}; /**<Vector which contains a set of references to weapon objects>*/

      convert << _num << " tanks were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
    case carrier:
      e = (Entity*)new Carrier(_name, _num, w2, _con);
        w2 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_CANNON)}; /**<Vector which contains a set of references to weapon objects>*/

      convert << _num << " carriers were made.";
      temp = convert.str();
      Logger::log(temp);
        w4 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_TORPEDO), this->weapons->getWeapon(CLASS_MISSILE)}; /**<Vector which contains a set of references to weapon objects>*/

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
        w3 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_MG160), this->weapons->getWeapon(CLASS_MG160), this->weapons->getWeapon(CLASS_MISSILE)}; /**<Vector which contains a set of references to weapon objects>*/

      convert << _num << " warships were made.";
        temp = convert.str();
      Logger::log(temp);
        w3 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_MG160), this->weapons->getWeapon(CLASS_MG160), this->weapons->getWeapon(CLASS_MISSILE)}; /**<Vector which contains a set of references to weapon objects>*/

      break;
    case submarine:
      e = (Entity*)new Submarine(_name, _num, w4, _con);
        w4 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_TORPEDO), this->weapons->getWeapon(CLASS_MISSILE)}; /**<Vector which contains a set of references to weapon objects>*/

      convert << _num << " submarines were made.";
        temp = convert.str();
      Logger::log(temp);
        w4 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_TORPEDO), this->weapons->getWeapon(CLASS_MISSILE)}; /**<Vector which contains a set of references to weapon objects>*/

    case fighterjet:
      e = (Entity*)new Fighterjet(_name, _num, w6, _con);
      convert << _num << " fighterjets were made.";
        temp = convert.str();
      Logger::log(temp);
        w6 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_BOMB), this->weapons->getWeapon(CLASS_MG160)}; /**<Vector which contains a set of references to weapon objects>*/

      break;
    case bomber:
      e = (Entity*)new Bomber(_name, _num, w6, _con);
        w6 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_BOMB), this->weapons->getWeapon(CLASS_MG160)}; /**<Vector which contains a set of references to weapon objects>*/

      convert << _num << " bombers were made.";
        temp = convert.str();
      Logger::log(temp);
        w6 = new vector<Weapon*> {this->weapons->getWeapon(CLASS_BOMB), this->weapons->getWeapon(CLASS_MG160)}; /**<Vector which contains a set of references to weapon objects>*/

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
