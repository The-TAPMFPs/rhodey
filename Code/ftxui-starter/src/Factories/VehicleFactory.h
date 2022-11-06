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

enum VEHICLE_TYPE {truck, tank, carrier, cargoship, warship, submarine, fighterjet, bomber, cargoplane};
class VehicleFactory : protected UnitFactory{
    private:
        VEHICLE_TYPE currVehicleType;
    public:
        VehicleFactory(std::string name, int num, VEHICLE_TYPE type);
        ~VehicleFactory();
        Entity* makeUnit();
        
};