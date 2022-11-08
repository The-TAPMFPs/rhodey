#pragma once

#include "UnitFactory.h"


enum VEHICLE_TYPE {truck, tank, carrier, cargoship, warship, submarine, fighterjet, bomber, cargoplane};
class VehicleFactory : public UnitFactory{
    private:
    public:
        VehicleFactory(std::string name, int num, Country * con);
        ~VehicleFactory();
        Entity* makeUnit();

};
