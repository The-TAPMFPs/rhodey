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
        int frameCount;

    public:
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

        void transitionTo(WarPhase* warPhase);
        void addCountryToSideA(Country* country);
        void addCountryToSideB(Country* country);
        Alliance* getSideCountryIsOn(Country* country);
        std::vector<Country*> getAllCountries();
        void changeState();
        void start();
        bool isOver();
        MapData getCurrentMapData();
        Region* getRegionAt(int x, int y);
        float getTravelDifficulty(MapCoords from, MapCoords to, bool teamA);
};