#pragma once

#include "../Country/Country.h"
#include <string>
#include <sstream>
#include <random>
#include "../uuid.h"

class Country; //Needed to resolve circular dependency

struct MapCoords
{
    int x;
    int y;
};


class Region {
    private:
        UUID uuid;
        std::string name;
        MapCoords coords; //The coordinates of the region (as a pin) on the map
        Country* possessor;
        // Battle* battle = nullptr;

    public:
        Region();
        Region(std::string name, int xCoord, int yCoord);
        Region(int xCoord, int yCoord);
        UUID getUUID();
        std::string getRegionName();
        void setRegionName(std::string name);
        MapCoords getCoords();
        void setRegionCoords(int xCoord, int yCoord);
        Country* getPossessor();
        void setPossessor(Country* possessor);
        // bool isEnemyRegion(Alliance* yourAlliance); // REMOVED: Regions are not aware of which alliance they belong to
};