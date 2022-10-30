#pragma once
#include <string>
#include <vector>
#include "AirVehicle.h"

using namespace std;

class Bomber :public AirVehicle{
    public:
    Bomber();
     void attack();
     void d();
     void transport();
    Entity* clone();

};