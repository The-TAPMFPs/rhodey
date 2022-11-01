//This class represents the map of all regions
#pragma once

#include <map>
#include <vector>
#include "Region.h"
#include "MapMemento.h"


typedef float** scalarField2D;

struct MapData
{
    std::vector<MapCoords> regionLocations; //TODO: Distinguish between regions for each alliance
    scalarField2D travelFieldA;
    scalarField2D travelFieldB;

    unsigned int width, height;
};


class MapMemento;

class Map {
    private:
        std::map<UUID, Region*> regions;
        //The travel distance fields are 2D scalar fields that determine
        //The difficulty of crossing any particular square on the map
        scalarField2D travelDifficultyField_allianceA;
        scalarField2D travelDifficultyField_allianceB;

        static float distToRegion(int x, int y, Region* r);

    public:
        static const unsigned int numRegions = 10;
        static const unsigned int mapW = 100, mapH = 100;


        Map();
        std::vector<Region*> getAllAvailableRegionsForAttack(Country *);

        scalarField2D getTravelFieldA();
        scalarField2D getTravelFieldB();
        std::vector<MapCoords> getRegionLocations();
        MapData getCurrentMapData();

        // THIS IS WHERE THE PROBLEM IS!
        MapMemento makeMemento();
        void SetMemento (MapMemento mem);

};