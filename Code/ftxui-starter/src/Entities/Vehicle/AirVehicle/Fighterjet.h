#pragma once
#include <string>
#include <vector>
#include "AirVehicle.h"

using namespace std;

class Fighterjet :public AirVehicle{
    public:
    Fighterjet();
     void attack();
     void d();
     void transport();
    Entity* clone();

};