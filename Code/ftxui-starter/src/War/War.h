#pragma once

#include "Alliance.h"
#include "MapRegions/Map.h"

class War {
    private:
        Alliance* teamA;
        Alliance* teamB;
        Map* map;
    public:
        War();
        void addCountryToSideA(Country* country);
        void addCountryToSideB(Country* country);
        void start();
};