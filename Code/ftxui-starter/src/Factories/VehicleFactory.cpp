#include "VehicleFactory.h"

VehicleFactory::VehicleFactory(std::string name, int hp, int num) {
  _name = name;
  _num = num;
  AR* ar;
  SMG* smg;
  Pistol* pis;
  w1 = new vector<Weapon*>{ar, smg, pis};
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
      e = (Entity*)new Tank(_name, _num, w1);
      return e;
    case carrier:
      e = (Entity*)new Carrier(_name, _num, w1);
      return e;
    case cargoship:
      e = (Entity*)new CargoShip(_name, _num, w1);
      return e;
    case warship:
      e = (Entity*)new Warship(_name, _num, w1);
      return e;
    case submarine:
      e = (Entity*)new Submarine(_name, _num, w1);
      return e;
    case fighterjet:
      e = (Entity*)new Fighterjet(_name, _num, w1);
      return e;
    case bomber:
      e = (Entity*)new Bomber(_name, _num, w1);
      return e;
    case cargoplane:
      e = (Entity*)new CargoPlane(_name, _num, w1);
      return e;
  }
}
