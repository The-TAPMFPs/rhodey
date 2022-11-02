#pragma once

#include "../Country/Alliance.h"
#include "../MapRegions/Map.h"
#include "WarPhases/WarPhase.h"

class WarPhase;

class War {
    private:
        WarPhase* warPhase;
        Alliance* teamA;
        Alliance* teamB;
        Map* map;

    public:
        War();
        War(WarPhase* warPhase);
        ~War();
        void transitionTo(WarPhase* warPhase);
        void addCountryToSideA(Country* country);
        void addCountryToSideB(Country* country);
        void changeState();
        void start();
        MapData getCurrentMapData();
};