#pragma once

#include "UnitFactory.h"


enum VEHICLE_TYPE {truck, tank, carrier, cargoship, warship, submarine, fighterjet, bomber, cargoplane};
class VehicleFactory : protected UnitFactory{
    private:
        VEHICLE_TYPE currVehicleType;
    public:
        VehicleFactory(std::string name, int num, VEHICLE_TYPE type, Country * con);
        ~VehicleFactory();
        Entity* makeUnit();

};
