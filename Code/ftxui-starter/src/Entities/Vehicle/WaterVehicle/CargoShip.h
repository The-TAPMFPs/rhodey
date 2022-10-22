#pragma once
#include <string>
#include <vector>
#include "WaterVehicle.h"

using namespace std;

class CargoShip :public WaterVehicle{
    public:
    CargoShip();
     void attack();
     void d();
     void transport();
    Entity* clone();

};