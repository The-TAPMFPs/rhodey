#include "VehicleFactory.h"

VehicleFactory::VehicleFactory(std::string name, int num, VEHICLE_TYPE type, Country * con) {
  _name = name;
  _num = num;
  _con = con;
  Mg160* mg;
  Bomb* bom;
  Cannon* can;
  Torpedo* tor;
  Missile* mis;
  w1 = new vector<Weapon*> {};
  w2 = new vector<Weapon*> {mg, can};
  w3 = new vector<Weapon*> {mg, can, mis};
  w4 = new vector<Weapon*> {tor, mis};
  w5 = new vector<Weapon*> {mg};
  w6 = new vector<Weapon*> {bom, mg};
  currVehicleType = type;
}

VehicleFactory::~VehicleFactory() {}

Entity* VehicleFactory::makeUnit() {
  std::string temp;
  switch (currVehicleType) {
    case truck:
      e = (Entity*)new Truck(_name, _num, w1, _con);
      temp = _num + " trucks were made.";
      Logger::log(temp);
      return e;                               
    case tank:
      e = (Entity*)new Tank(_name, _num, w2, _con);
      temp = _num + " tanks were made.";
      Logger::log(temp);
      return e;
    case carrier:
      e = (Entity*)new Carrier(_name, _num, w1, _con);
      temp = _num + " carriers were made.";
      Logger::log(temp);
      return e;
    case cargoship:
      e = (Entity*)new CargoShip(_name, _num, w1, _con);
      temp = _num + " cargoships were made.";
      Logger::log(temp);
      return e;
    case warship:
      e = (Entity*)new Warship(_name, _num, w3, _con);
      temp = _num + " warships were made.";
      Logger::log(temp);
      return e;
    case submarine:
      e = (Entity*)new Submarine(_name, _num, w4, _con);
      temp = _num + " submarines were made.";
      Logger::log(temp);
      return e;
    case fighterjet:
      e = (Entity*)new Fighterjet(_name, _num, w1, _con);
      temp = _num + " fighterjets were made.";
      Logger::log(temp);
      return e;
    case bomber:
      e = (Entity*)new Bomber(_name, _num, w6, _con);
      temp = _num + " bombers were made.";
      Logger::log(temp);
      return e;
    case cargoplane:
      e = (Entity*)new CargoPlane(_name, _num, w1, _con);
      temp = _num + " cargo planes were made.";
      Logger::log(temp);
      return e;
  }
}
