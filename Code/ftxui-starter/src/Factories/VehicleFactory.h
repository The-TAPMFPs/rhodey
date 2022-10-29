#pragma once

#include "UnitFactory.h"
#include <memory>

enum VEHICLE_TYPE {truck, tank, carrier, cargoship, warship, submarine, fighterjet, bomber, cargoplane};
class VehicleFactory : protected UnitFactory{
    private:
        VEHICLE_TYPE currVehicleType;
    public:
        VehicleFactory(std::string name, int hp, int num);
        ~VehicleFactory();
        void setVehicleType(VEHICLE_TYPE type);
        Entity* makeUnit();
        
};