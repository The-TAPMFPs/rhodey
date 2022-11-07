#pragma once

#include "UnitFactory.h"


class VehicleFactory : public UnitFactory{
    private:
        VEHICLE_TYPE currVehicleType;
    public:
        VehicleFactory(std::string name, int num, VEHICLE_TYPE type, Country * con);
        ~VehicleFactory();
        Entity* makeUnit();

};
