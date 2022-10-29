#pragma once
#include <string>
#include <vector>
#include "Entity.h"

using namespace std;

class Troop :public Entity{
    public:
    Troop();
    virtual void attack();
    virtual void defend();
    virtual void transport();
    Entity* clone();

};