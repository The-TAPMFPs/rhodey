#include "VehicleFactory.h"

VehicleFactory::VehicleFactory(std::string name, int num) {
  _name = name;
  _num = num;
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
  //Need to make more guns
}

VehicleFactory::~VehicleFactory() {}

void VehicleFactory::setVehicleType(VEHICLE_TYPE type) {
  currVehicleType = type;
}

Entity* VehicleFactory::makeUnit() {
  switch (currVehicleType) {
    case truck:
      e = (Entity*)new Truck(_name, _num, w1);
      return e;
    case tank:
      e = (Entity*)new Tank(_name, _num, w2);
      return e;
    case carrier:
      e = (Entity*)new Carrier(_name, _num, w1);
      return e;
    case cargoship:
      e = (Entity*)new CargoShip(_name, _num, w1);
      return e;
    case warship:
      e = (Entity*)new Warship(_name, _num, w3);
      return e;
    case submarine:
      e = (Entity*)new Submarine(_name, _num, w4);
      return e;
    case fighterjet:
      e = (Entity*)new Fighterjet(_name, _num, w1);
      return e;
    case bomber:
      e = (Entity*)new Bomber(_name, _num, w6);
      return e;
    case cargoplane:
      e = (Entity*)new CargoPlane(_name, _num, w1);
      return e;
  }
}
