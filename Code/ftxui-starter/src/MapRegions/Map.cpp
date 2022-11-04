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
    int dx = x - regionCoords.x*2; //Scale to map proportions
    int dy = y - regionCoords.y*4;

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

//Return the region at the specified coordinates
//Returns nullptr if no such region exists
Region* Map::getRegionAt(int x, int y)
{
    for(auto it = regions.begin(); it != regions.end(); it++)
    {
        MapCoords coords = it->second->getCoords();
        if(coords.x == x && coords.y == y)
        {
            return it->second;
        }
    }
    return nullptr;
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

//Returns the linearly interpolated point between two mapCoords
//t in [0, 1] inclusive
MapCoords lerp(MapCoords a, MapCoords b, float t)
{
    int dx = (a.x - b.x) * t;
    int dy = (a.y - b.y) * t;

    return {b.x + dx, b.y + dy};
}

int dist(MapCoords a, MapCoords b)
{
    int dx = a.x-b.x;
    int dy = a.y-b.y;

    return sqrt(dx*dx + dy*dy);
}

//Get a measure of the difficulty for a country from teamA/teamB to travel linearly between two points on the map
float Map::getTravelDifficulty(MapCoords from, MapCoords to, bool teamA)
{
    float sum = 0.0f;

    int distance = dist(from, to);

    for(int t = 0; t <= distance; t++)
    {
        MapCoords samplePt = lerp(from, to, ((float)t)/distance);

        sum += teamA ?
                    this->travelDifficultyField_allianceA[samplePt.x][samplePt.y]:
                    this->travelDifficultyField_allianceB[samplePt.x][samplePt.y];
    }

    return sum;
}

MapMemento Map::makeMemento()
{
    MapData md = getCurrentMapData();
    return MapMemento(md);
}
void Map::SetMemento(MapMemento md){
    this->travelDifficultyField_allianceB = md.getState()->travelFieldB;
    this->travelDifficultyField_allianceA = md.getState()->travelFieldA;
}