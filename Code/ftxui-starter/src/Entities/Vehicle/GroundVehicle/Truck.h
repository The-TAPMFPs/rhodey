#pragma once
#include <string>
#include <vector>
#include "GroundVehicle.h"

using namespace std;

class Truck :public GroundVehicle{
    public:
    Truck();
     void attack();
     void d();
     void transport();
    Entity* clone();

};