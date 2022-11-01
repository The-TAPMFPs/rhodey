#pragma once

#include "../../Country/Country.h"
#include "../../MapRegions/Region.h"
#include "../../Military/Forces.h"
#include <vector>

class Battle{
    private:
        Country* _country;
        Region* _region;
        std::vector<Forces*> _attackingForces;
        std::vector<Forces*> _defendingForces;
    public:
        Battle(std::vector<Forces*> attackingForces, std::vector<Forces*> defendingForces, Region* country, Country* region);
        void start();
        void end();
        ~Battle();
};
