#include "Map.h"
#include <cmath>

Map::Map()
{
    //Randomly initialize regions
    this->regions = std::map<UUID, Region*>();

    for(int i = 0; i < numRegions; i++)
    {
        Region* r = new Region();
        //TODO: Check position is not already taken
        regions.emplace(r->getUUID(), r);
    }

    //Initialize travel difficulty field to 0's
    this->travelDifficultyField_allianceA = new float*[mapW];
    this->travelDifficultyField_allianceB = new float*[mapW];
    for(int x = 0; x < mapW; x++)
    {
        this->travelDifficultyField_allianceA[x] = new float[mapH];
        this->travelDifficultyField_allianceB[x] = new float[mapH];
        for(int y = 0; y < mapH; y++)
        {
            this->travelDifficultyField_allianceA[x][y] = 0.0f;
            this->travelDifficultyField_allianceB[x][y] = 0.0f;
        }
    }

    //Fill field based on region proximity
    for(auto r = regions.begin(); r != regions.end(); r++)
    {
        for(int x = 0; x < mapW; x++)
        {
            for(int y = 0; y < mapH; y++)
            {
                //TODO: Determine whether the country is part of team A or B
                // if(r->second->getPossessor().allies)
                if(true)
                {
                    this->travelDifficultyField_allianceA[x][y] += 1.0f/distToRegion(x, y, r->second);
                }
                else
                {
                    this->travelDifficultyField_allianceB[x][y] += 1.0f/distToRegion(x, y, r->second);
                }
            }
        }
    }
}

float Map::distToRegion(int x, int y, Region* r)
{
    MapCoords regionCoords = r->getCoords();
    int dx = x - regionCoords.x;
    int dy = y - regionCoords.y;

    //TODO: Consider multiplying by the 'danger' of the region,
    //      i.e. How big of a threat the enemy region poses
    return std::sqrt(dx*dx + dy*dy); //TODO: See if this works better as square magnitude
}

scalarField2D Map::getTravelFieldA()
{
    return this->travelDifficultyField_allianceA;
}
scalarField2D Map::getTravelFieldB()
{
    return this->travelDifficultyField_allianceA;
}

std::vector<MapCoords> Map::getRegionLocations()
{
    std::vector<MapCoords> res;

    for(auto it = regions.begin(); it != regions.end(); it++)
    {
        res.push_back(it->second->getCoords());
    }

    return res;
}

MapData Map::getCurrentMapData()
{
    return
    {
        this->getRegionLocations(),
        this->travelDifficultyField_allianceA,
        this->travelDifficultyField_allianceB,
        this->mapW,
        this->mapH
    };
    
}
MapMemento Map::makeMemento()
{
    //REMOVED: Causing compilation errors
    //TODO: Fix
    // MapData m = getCurrentMapData();
    // return new MapMemento(&m);

    // return nullptr;

    MapData md = getCurrentMapData();
    return MapMemento(md);
}
void Map::SetMemento(MapMemento md){
    
    this->mapH= md.height;
    this->mapW= md.width;
    this->travelDifficultyField_allianceB = md.travelFieldB;
    this->travelDifficultyField_allianceA = md.travelFieldA;
 
    // std::map<UUID, Region*> newRegions = std::map<UUID, Region*>();//need to fix 
    // for(int i = 0; i < md.regionLocations.size() ; i++)
    // {
    //     Region* r = md.regionLocations.at(i);
    //     regions.emplace(r->getUUID(), r);
    // }
    // this->region = newRegions;

}