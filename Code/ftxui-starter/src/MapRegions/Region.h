#pragma once

#include "../Country/Country.h"
#include <string>

class Country; //Needed to resolve circular dependency

struct MapCoords
{
    int x;
    int y;
};

//The RegionUUID is used for uniquely referencing a region when, for example, it is stored as a Memento
typedef std::string RegionUUID;

class Region {
    private:
        RegionUUID uuid;
        std::string name;
        MapCoords coords; //The coordinates of the region (as a pin) on the map
        Country* possessor;
        // Battle* battle = nullptr;
        static RegionUUID generateUUID(); //Called by constructor
        static std::string generateName(); //Called by constructor

    public:
        Region(); //TODO: Randomly generate UUID on initialization
        Region(std::string name, int xCoord, int yCoord);
        Region(int xCoord, int yCoord);
        RegionUUID getUUID();
        std::string getRegionName();
        void setRegionName(std::string name);
        MapCoords getCoords();
        void setRegionCoords(int xCoord, int yCoord);
        Country* getPossessor();
        void setPossessor(Country* possessor);
        // bool isEnemyRegion(Alliance* yourAlliance); // REMOVED: Regions are not aware of which alliance they belong to
};