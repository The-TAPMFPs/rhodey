#pragma once

// #include "../Country/Country.h"
#include <string>
#include <sstream>
#include <random>
#include "../uuid.h"

class Country;

struct MapCoords
{
    int x;
    int y;
};

//Define a total 
inline bool operator<(const MapCoords& a, const MapCoords& b)
{
    //Coords are different if either the x-coords are different
    //OR the y-coords are different
    return a.x < b.x || a.y < b.y;
}

class Region {
    private:
        UUID uuid;
        std::string name;
        MapCoords coords; //The coordinates of the region (as a pin) on the map
        Country* possessor;
        // Battle* battle = nullptr;

    public:
        Region(Country* possessor);
        Region(std::string name, int xCoord, int yCoord, Country* possessor);
        Region(int xCoord, int yCoord, Country* possessor);
        UUID getUUID();
        std::string getRegionName();
        void setRegionName(std::string name);
        MapCoords getCoords();
        void setRegionCoords(int xCoord, int yCoord);
        Country* getPossessor();
        void setPossessor(Country* possessor);
        // bool isEnemyRegion(Alliance* yourAlliance); // REMOVED: Regions are not aware of which alliance they belong to
};