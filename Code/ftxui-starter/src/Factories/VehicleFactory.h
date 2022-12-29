#pragma once

#include "UnitFactory.h"
#include "Entities/Vehicle/GroundVehicle/Tank.h"
#include "Entities/Vehicle/GroundVehicle/Truck.h"
#include "Entities/Vehicle/AirVehicle/Bomber.h"
#include "Entities/Vehicle/AirVehicle/CargoPlane.h"
#include "Entities/Vehicle/AirVehicle/Fighterjet.h"
#include "Entities/Vehicle/WaterVehicle/CargoShip.h"
#include "Entities/Vehicle/WaterVehicle/Carrier.h"
#include "Entities/Vehicle/WaterVehicle/Submarine.h"
#include "Entities/Vehicle/WaterVehicle/Warship.h"


class VehicleFactory : public UnitFactory {
    public:
        VehicleFactory(std::string name, int num, Country * con);
        ~VehicleFactory();
        Entity* makeUnit();

};
