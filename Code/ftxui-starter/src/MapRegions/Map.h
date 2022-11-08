//This class represents the map of all regions
#pragma once

#include <map>
#include <vector>
#include <cmath>
#include <set>
#include "Region.h"
#include "MapMemento.h"
#include "../Country/Country.h"
// #include "../War/War.h"
// #include "OccupancyTable.h"
#include "OccupancyTable.h"


class Country;
typedef float** scalarField2D;

struct MapData
{
    std::vector<MapCoords> regionLocations; //TODO: Distinguish between regions for each alliance
    scalarField2D travelFieldA;
    scalarField2D travelFieldB;

    unsigned int width, height;
};

struct HeightMap
{
    scalarField2D travelFieldA;
    scalarField2D travelFieldB;
};


// class OccupancyTable;
class MapMemento;
// class War;
class OccupancyTable;

class Map {
    friend class OccupancyTable;
    private:
        std::map<UUID, Region*> regions;
        // War* war;
        //The travel distance fields are 2D scalar fields that determine
        //The difficulty of crossing any particular square on the map
        scalarField2D travelDifficultyField_allianceA;
        scalarField2D travelDifficultyField_allianceB;
        OccupancyTable* occupancyTable;

        // OccupancyTable* occupancyTable;

        static float distToRegion(int x, int y, Region* r);
        // void randomInitializeRegions(int numRegions);
        void randomInitializeRegions(int numRegions, std::vector<Country*> allCountries);
        void recalculateTravelFields();

    public:
        static const unsigned int numRegions = 100;
        static const unsigned int mapW = 100, mapH = 100;


        // Map(War* war);
        Map(std::vector<Country*> allCountries,bool testing = false);
        ~Map();
        std::vector<Region*> getAllAvailableRegionsForAttack(Country *);

        scalarField2D getTravelFieldA();
        scalarField2D getTravelFieldB();
        std::vector<MapCoords> getRegionLocations();
        MapData getCurrentMapData();
        Region* getRegionAt(int x, int y);
        float getTravelDifficulty(MapCoords from, MapCoords to, bool weAreTeamA);

        OccupancyTable* getOccupancyTable();
        float getEnemyRatioInRegion(Region* region, bool teamA);

        std::vector<Region*> getRegionsOwnedBy(Country* country);
        std::vector<Region*> getRegionsOwnedBy(bool teamA);

        // Region* getFriendRegionWithHighestEnemyRatio(bool teamA);
        // Region* getEnemyRegionWithHighestFriendRatio(bool teamA);
        // Region* getFriendRegionWithLowestEnemyRatio(bool teamA);
        Region* getTeamsRegionWithEnemyRatio(bool weAreTeamA, bool getEnemyRegion, bool highest);


        // THIS IS WHERE THE PROBLEM IS!
        MapMemento* makeMemento();
        void setMemento (MapMemento* mem);

};
