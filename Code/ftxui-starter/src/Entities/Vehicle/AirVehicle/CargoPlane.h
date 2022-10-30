#pragma once
#include <string>
#include <vector>
#include "AirVehicle.h"

using namespace std;

class CargoPlane :public AirVehicle{
    public:
    CargoPlane();
     void attack();
     void d();
     void transport();
    Entity* clone();

};