#pragma once

#include "ftxui/component/event.hpp"                // for Event

#include "../Country/Alliance.h"
#include "../MapRegions/Map.h"
#include "WarPhases/WarPhase.h"

class WarPhase;

class War {
    private:
        WarPhase* warPhase;
        Map* map;

    public:
        Alliance* teamA;
        Alliance* teamB;
        static std::string warState;
        static std::string warStateDesc;
        War();
        War(WarPhase* warPhase);
        ~War();

        void step(); //The main game loop
        bool onEvent(ftxui::Event e);

        void transitionTo(WarPhase* warPhase);
        void addCountryToSideA(Country* country);
        void addCountryToSideB(Country* country);
        void changeState();
        void start();
        bool isOver();
        MapData getCurrentMapData();
        Region* getRegionAt(int x, int y);
};