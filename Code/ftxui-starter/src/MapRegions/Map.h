//This class represents the map of all regions
#pragma once

#include <map>
#include <vector>
#include "Region.h"

class Map {
    private:
        std::map<RegionUUID, Region*> regions;

    public:
        std::vector<Region*> getAllAvailableRegionsForAttack(Country *);
};