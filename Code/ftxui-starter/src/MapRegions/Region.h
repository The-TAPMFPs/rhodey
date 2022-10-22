#pragma once

#include "Country/Country.h"
#include <string>

//The RegionUUID is used for uniquely referencing a region when, for example, it is stored as a Memento
typedef std::string RegionUUID;

class Region {
    private:
        RegionUUID uuid;
        std::string name;
        int xCoord, yCoord; //The coordinates of the region (as a pin) on the map
        Country* possessor; //REMOVED: In favour of the Country
        // Battle* battle = nullptr;

    public:
        Region(); //TODO: Randomly generate UUID on initialization
        RegionUUID getUUID();
        bool isEnemyRegion(Alliance* yourAlliance);
};