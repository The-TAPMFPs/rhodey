#pragma once

#include "ftxui/component/event.hpp"                // for Event
#include "ftxui/screen/color.hpp"                   // for Color, Color::Red, Color::Blue, Color::Green, ftxui

#include "../Country/Alliance.h"
#include "../MapRegions/Map.h"
#include "WarPhases/WarPhase.h"
#include "Narrative/Narrative.h"
#include "Narrative/NarrativeDirector.h"
class WarPhase;

class War {
#ifdef UNIT_TEST
    public:
#else
    private:
#endif
        WarPhase* warPhase;
        Map* map;
        int stepCount;

    public:
        bool endWar = false;
        Alliance* teamA;
        Alliance* teamB;

        static Narrative narrative;
        static std::string warState;
        static std::string warStateDesc;
        static std::vector<std::string> warStateThumbnail;
        static int warStateThumbnailFrameCount;
        static ftxui::Color warStateThumbnailColor;
        War();
        ~War();

        void step(); //The main game loop
        bool onEvent(ftxui::Event e);
        int getStepCount();

        void transitionTo(WarPhase* warPhase);
        void addCountryToSideA(Country* country);
        void addCountryToSideB(Country* country);
        Alliance* getSideCountryIsOn(Country* country);
        std::vector<Country*> getAllCountries();
        Country* getCountryInAllianceWithHighestTroopCount(bool teamA);
        Country* getCountryInAllianceWithHighestVehicleCount(bool teamA);
        void changeState();
        void start();
        bool isOver();
        Map* getMap();
};