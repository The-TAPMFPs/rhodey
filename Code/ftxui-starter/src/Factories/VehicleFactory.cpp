#include "VehicleFactory.h"

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
VehicleFactory::VehicleFactory(std::string name, int num, VEHICLE_TYPE type, Country * con) {
  _name = name;
  _num = num;
  _con = con;
  Mg160* mg; /**<Reference to different weapon MG160 object>*/
  Bomb* bom; /**<Reference to different weapon Bomb object>*/
  Cannon* can; /**<Reference to different weapon Cannon object>*/
  Torpedo* tor; /**<Reference to different weapon Torpedo object>*/
  Missile* mis; /**<Reference to different weapon Missle object>*/
  w1 = new vector<Weapon*> {}; /**<Vector which contains a set of references to weapon objects>*/
  w2 = new vector<Weapon*> {mg, can}; /**<Vector which contains a set of references to weapon objects>*/
  w3 = new vector<Weapon*> {mg, can, mis}; /**<Vector which contains a set of references to weapon objects>*/
  w4 = new vector<Weapon*> {tor, mis}; /**<Vector which contains a set of references to weapon objects>*/
  w5 = new vector<Weapon*> {mg}; /**<Vector which contains a set of references to weapon objects>*/
  w6 = new vector<Weapon*> {bom, mg}; /**<Vector which contains a set of references to weapon objects>*/
}

/**
 * @fn ~VehicleFactory()
 * @brief The Destructor of the VehicleFactory class.
 */
VehicleFactory::~VehicleFactory() {}

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
      convert << _num << " trucks were made.";
      temp = convert.str();
      Logger::log(temp);
      break;
    case tank:
      e = (Entity*)new Tank(_name, _num, w2, _con);
      convert << _num << " tanks were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
    case carrier:
      e = (Entity*)new Carrier(_name, _num, w1, _con);
      convert << _num << " carriers were made.";
      temp = convert.str();
      Logger::log(temp);
      break;
    case cargoship:
      e = (Entity*)new CargoShip(_name, _num, w1, _con);
      convert << _num << " cargoships were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
    case warship:
      e = (Entity*)new Warship(_name, _num, w3, _con);
      convert << _num << " warships were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
    case submarine:
      e = (Entity*)new Submarine(_name, _num, w4, _con);
      convert << _num << " submarines were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
    case fighterjet:
      e = (Entity*)new Fighterjet(_name, _num, w1, _con);
      convert << _num << " fighterjets were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
    case bomber:
      e = (Entity*)new Bomber(_name, _num, w6, _con);
      convert << _num << " bombers were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
    case cargoplane:
      e = (Entity*)new CargoPlane(_name, _num, w1, _con);
      convert << _num << " cargo planes were made.";
        temp = convert.str();
      Logger::log(temp);
      break;
  }
return e;
}
