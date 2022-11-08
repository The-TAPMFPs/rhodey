#include "VehicleFactory.h"
#include "Entities/WeaponTemplateMethod/Weapon.h"
#include "../Country/Country.h"
#include "../MapRegions/Map.h"

VehicleFactory::VehicleFactory(std::string name, int num, VEHICLE_TYPE type, Country * con) {
  _name = name;
  _num = num;
  _con = con;
  w1 = new vector<Weapon*> {};
  w2 = new vector<Weapon*> {new Mg160(), new TankCannon()};
  w3 = new vector<Weapon*> {new Mg160(), new Cannon(), new Missile()};
  w4 = new vector<Weapon*> {new Torpedo(), new Missile()};
  w5 = new vector<Weapon*> {new Mg160()};
  w6 = new vector<Weapon*> {new Bomb(), new Mg160()};
  currVehicleType = type;
}

VehicleFactory::~VehicleFactory() {}

Entity* VehicleFactory::makeUnit() {
  std::string temp;
std::stringstream convert;
  switch (currVehicleType) {
    case truck:
      e = (Entity*)new Truck(_name, _num, w1, _con);
      convert << _num << " trucks were made.";
      temp = convert.str();
      Logger::log(temp);
      w1 = new vector<Weapon*> {};
    case tank:
      e = (Entity*)new Tank(_name, _num, w2, _con);
      convert << _num << " tanks were made.";
        temp = convert.str();
      Logger::log(temp);
      w2 = new vector<Weapon*> {new Mg160(), new TankCannon()};
    case carrier:
      e = (Entity*)new Carrier(_name, _num, w4, _con);
      convert << _num << " carriers were made.";
        temp = convert.str();
      Logger::log(temp);
      w4 = new vector<Weapon*> {new Torpedo(), new Missile()};
    case cargoship:
      e = (Entity*)new CargoShip(_name, _num, w1, _con);
      convert << _num << " cargoships were made.";
        temp = convert.str();
      Logger::log(temp);
      w1 = new vector<Weapon*> {};
    case warship:
      e = (Entity*)new Warship(_name, _num, w3, _con);
      convert << _num << " warships were made.";
        temp = convert.str();
      Logger::log(temp);
      w3 = new vector<Weapon*> {new Mg160(), new Cannon(), new Missile()};
    case submarine:
      e = (Entity*)new Submarine(_name, _num, w4, _con);
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
    case bomber:
      e = (Entity*)new Bomber(_name, _num, w6, _con);
      convert << _num << " bombers were made.";
        temp = convert.str();
      Logger::log(temp);
      w6 = new vector<Weapon*> {new Bomb(), new Mg160()};
    case cargoplane:
      e = (Entity*)new CargoPlane(_name, _num, w1, _con);
      convert << _num << " cargo planes were made.";
        temp = convert.str();
      Logger::log(temp);
      w1 = new vector<Weapon*> {};
  }
  this->_con->getMap()->getOccupancyTable()->addEntity(e, this->_con->getCapital());
  return e;
}
