#pragma once
#include "../Entities/Entity.h"
#include "../Entities/WeaponTemplateMethod/Weapon.h"
#include "../Entities/Vehicle/GroundVehicle/Tank.h"
#include "../Entities/Vehicle/GroundVehicle/Truck.h"
#include "../Entities/Vehicle/AirVehicle/Bomber.h"
#include "../Entities/Vehicle/AirVehicle/CargoPlane.h"
#include "../Entities/Vehicle/AirVehicle/Fighterjet.h"
#include "../Entities/Vehicle/WaterVehicle/CargoShip.h"
#include "../Entities/Vehicle/WaterVehicle/Carrier.h"
#include "../Entities/Vehicle/WaterVehicle/Submarine.h"
#include "../Entities/Vehicle/WaterVehicle/Warship.h"
#include "../Entities/Troop/Troop.h"
#include "../logger.h"
class Country;
class UnitFactory{
    protected:
        std::string _name;
        int _num;
        Country * _con;
        vector<Weapon *> * w1;
        vector<Weapon *> * w2;
        vector<Weapon *> * w3;
        vector<Weapon *> * w4;
        vector<Weapon *> * w5;
        vector<Weapon *> * w6;
        Entity* e;
    public:
        UnitFactory(std::string name, int num, Country * con);
        UnitFactory(std::string name, int num, VEHICLE_TYPE type, Country * con);
        virtual Entity* makeUnit() = 0;


};
