/**
 * \file Map.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
#include "Map.h"

/**
 * \fn void Map::Map(std::vector<Country*> allCountries)
 * \brief constructs a new Map , sets travel difficulty fields 
 * @param allCountries a vector filled with countries 
 * 
 */
Map::Map(std::vector<Country*> allCountries)
{
    // this->occupancyTable = new OccupancyTable(this);

    // Region* r = new Region(0,0);
    // //TODO: Check position is not already taken
    // regions.emplace(r->getUUID(), r);

    // r = new Region(49,24);
    // regions.emplace(r->getUUID(), r);

    //Initialize travel difficulty field to 0's
    this->randomInitializeRegions(this->numRegions, allCountries);

    //Create travel difficulty fields
    this->travelDifficultyField_allianceA = new float*[mapW];/**creates travel difficulty fields */
    this->travelDifficultyField_allianceB = new float*[mapW];
    for(int x = 0; x < mapW; x++)
    {
        this->travelDifficultyField_allianceA[x] = new float[mapH];
        this->travelDifficultyField_allianceB[x] = new float[mapH];
    }

    this->recalculateTravelFields();
}

//Call this whenever the outcome of a battle changes a Region's occupancy
/**
 * \fn void Map::reculculateTravelFields()
 * \brief function recalculates the travel fields as a circumstance of a battle 
 */
void Map::recalculateTravelFields()
{
    //Reset all points to 0
    for(int x = 0; x < mapW; x++)
    {
        for(int y = 0; y < mapH; y++)
        {
            this->travelDifficultyField_allianceA[x][y] = 0.0f;
            this->travelDifficultyField_allianceB[x][y] = 0.0f;
        }
    }

    //Fill field based on region proximity
    for(auto r = this->regions.begin(); r != this->regions.end(); r++)
    {
        for(int x = 0; x < mapW; x++)
        {
            for(int y = 0; y < mapH; y++)
            {
                if(r->second->getPossessor()->getAlliance()->isTeamA())
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

/**
 * \fn void Map::randomInitializeRegions(int numRegions, std::vector<Country*> allCountries)
 * \brief function that creates regions in such a way that it is random everytime
 * @param numRegions number of regions 
 * @param allCountries a vector of country pointers 
 * 
 */
void Map::randomInitializeRegions(int numRegions, std::vector<Country*> allCountries)
{
    if(allCountries.size() == 0) { return; } //No countries, therefore cannot make regions
    for(auto r = this->regions.begin(); r != this->regions.end(); r++) { delete r->second; } //Delete any old regions

    //Randomly initialize regions
    this->regions = std::map<UUID, Region*>();/**a variable that randomly initializes regions*/

    std::set<MapCoords> coords;/**a set of map co-ordinates */

    //Insert regions in such a way that no two regions have the same coordinates
    for(int i = 0; i < numRegions; i++)
    {
        MapCoords toTryInsert = { uuid::randomInt(0, 49), uuid::randomInt(0, 24) };/**variable of type MapCoords*/

        while(coords.count(toTryInsert)) //While there is a collision
        {
            toTryInsert = {uuid::randomInt(0, 49), uuid::randomInt(0, 24)};
        }
        coords.insert(toTryInsert);

        Country* possessor = allCountries[uuid::randomInt(0, allCountries.size()-1)];/**a pointer to a Country*/

        Region* r = new Region(toTryInsert.x, toTryInsert.y, possessor);/**a pointer to a Region*/
        regions.emplace(r->getUUID(), r);
    }
}
/**
 * \fn float Map::distToRegion(int x, int y, Region* r)
 * \brief function that calculates the distance of one region to another 
 * @param x a regions x co-ordinate 
 * @param y a regions y co-ordinate
 * @param r a pointer to a region 
 * @return returns the square root of the product of dx added to the product of dy
 * 
 */
float Map::distToRegion(int x, int y, Region* r)
{
    MapCoords regionCoords = r->getCoords();
    int dx = x - regionCoords.x*2; /*variables that scale to map proportions*/
    int dy = y - regionCoords.y*4;

    //TODO: Consider multiplying by the 'danger' of the region,
    //      i.e. How big of a threat the enemy region poses
    return std::sqrt(dx*dx + dy*dy); //TODO: See if this works better as square magnitude
}
/**
 * \fn scalarField2D Map::getTravelFieldA()
 * \brief a function that returns the travel difficulty of allianceA
 * \return returns travel difficulty field of allianceA
*/
scalarField2D Map::getTravelFieldA()
{
    return this->travelDifficultyField_allianceA;
}
/**
 * \fn scalarField2D Map::getTravelFieldB()
 * \brief a function that returns the travel difficulty of allianceB
 * \return returns travel difficulty field of allianceB
*/
scalarField2D Map::getTravelFieldB()
{
    return this->travelDifficultyField_allianceB;
}
/**
 * \fn vector<MapCoords> Map::getRegionLocations()
 * \brief a function that pushes map co-ordinates to the vector of map co-ordinates
 * \return returns the location of the added co-ordinates
*/
std::vector<MapCoords> Map::getRegionLocations()
{
    std::vector<MapCoords> res;/**a vector called res of map co-ordinates*/

    for(auto it = regions.begin(); it != regions.end(); it++)
    {
        res.push_back(it->second->getCoords());
    }

    return res;
}

//Return the region at the specified coordinates
//Returns nullptr if no such region exists
/**
 * \fn Region* Map::getRegionAt(int x, int y)
 * \brief a function that 
 * @param x x co-ordinate of the region you want to fetch 
 * @param y y co-ordinate of the region you want to fetch
 * \return returns nullptr if no such region exists 
 * \return returns the region at specified co-ordinates
*/
Region* Map::getRegionAt(int x, int y)
{
    for(auto it = regions.begin(); it != regions.end(); it++)
    {
        MapCoords coords = it->second->getCoords();/**a variable of type MapCoords that stores co-ordinates*/
        if(coords.x == x && coords.y == y)
        {
            return it->second;
        }
    }
    return nullptr;
}
/**
 * \fn Mapdata Map::getCurrentMapData()
 * \brief retrieves the most recent map data 
 * \return returns the most recent map data 
*/
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
/**
 * \fn MapCoords lerp(MapCoords a, MapCoords b, float t)
 * \brief interpolates a point between two mapCoords
 * @param a co-ordinates from first region
 * @param b co-ordinates from second region
 * @param t value between 0 and 1 in which we want a interpolated point 
 * \return we return a set of x and y co-ordinates which is the linearly interpolated point 
 * 
*/
MapCoords lerp(MapCoords a, MapCoords b, float t)
{
    int dx = (a.x - b.x) * t;
    int dy = (a.y - b.y) * t;

    return {b.x + dx, b.y + dy};
}
/**
 * \fn int dist(MapCoords a, MapCoords b)
 * \brief calculates distance between 2 sets of co-ordiantes 
 * @param a co-ordinates from first region
 * @param b co-ordinates from second region
 * \return we return the distance between 2 regions 
 * 
*/
int dist(MapCoords a, MapCoords b)
{
    int dx = a.x-b.x;
    int dy = a.y-b.y;

    return sqrt(dx*dx + dy*dy);
}

//Get a measure of the difficulty for a country from teamA/teamB to travel linearly between two points on the map
/**
 * \fn Map::getTravelDifficulty(MapCoords from, MapCoords to, bool teamA)
 * \brief function that gets the travel difficulty from 1 region to abother region 
 * @param from co-ordinates from the region we want to start at
 * @param to co-ordinates from the region we want to end up at
 * @param teamA true or false value  
 * \return we return the travel difficulty from 1 region to another 
 * 
*/
float Map::getTravelDifficulty(MapCoords from, MapCoords to, bool teamA)
{
    float sum = 0.0f;/**a float variable called sum*/

    int distance = dist(from, to);/**distance variable from 2 different regions*/
    if(distance == 0)
    {
        return 0;
    }

    for(int t = 0; t <= distance; t++)
    {
        MapCoords samplePt = lerp(from, to, ((float)t)/distance);

        sum += teamA ?
                    this->travelDifficultyField_allianceA[samplePt.x][samplePt.y]:
                    this->travelDifficultyField_allianceB[samplePt.x][samplePt.y];
    }

    return sum;
}
/**
 * \fn MapMemento* Map::makeMemento()
 * \brief function that creates a new memento 
 * \return we return a new MapMemento
*/
MapMemento* Map::makeMemento()
{
    HeightMap hm = {/**variable of type Heightmap that stores the travel difficulty of allianceA and B*/
        this->travelDifficultyField_allianceA,
        this->travelDifficultyField_allianceB
    };
    return new MapMemento(hm);
}
/**
 * \fn void Map::setMemento(MapMemento* mem)
 * \brief function that sets a MapMemento
 * @param mem a pointer to a MapMemento 
*/
void Map::setMemento(MapMemento* mem){
    this->travelDifficultyField_allianceA = mem->getState()->travelFieldA;
    this->travelDifficultyField_allianceB = mem->getState()->travelFieldB;
     // this is fine becuase it is a stack and the recieved memento should not be accessed again
}
/**
 * \fn void Map::~Map()
 * \brief the destructor for the Map class , Deallocates travel fields 
*/
Map::~Map()
{
    //Deallocate travel fields
    for(int x = 0; x < mapW; x++)
    {
        delete [] this->travelDifficultyField_allianceA[x];
        delete [] this->travelDifficultyField_allianceB[x];
    }
    delete [] this->travelDifficultyField_allianceA;
    delete [] this->travelDifficultyField_allianceA;
}
