#pragma once

#include "Country/Country.h"
#include <string>
#include <uuids.h>

//The RegionUUID is used for uniquely referencing a region when, for example, it is stored as a Memento
typedef std::string RegionUUID;

class Region {
    private:
        RegionUUID uuid;
        std::string name;
        int xCoord, yCoord; //The coordinates of the region (as a pin) on the map
        // Country* possessor; //REMOVED: In favour of the Country
        // Battle* battle = nullptr;
        generateUUID();

    public:
        Region(); //TODO: Randomly generate UUID on initialization
        Region(std::string name, int xCoord, int yCoord);
        Region(int xCoord, int yCoord);
        RegionUUID getUUID();
        std::string getRegionName();
        void setRegionName(std::string name);
        int* getCoords();
        void setRegionCoords(int xCoord, int yCoord);
        // bool isEnemyRegion(Alliance* yourAlliance); // REMOVED: Regions are not aware of which alliance they belong to
};