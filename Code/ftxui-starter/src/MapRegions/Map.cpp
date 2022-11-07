#include "Map.h"

Map::Map(std::vector<Country*> allCountries, bool testing)
{
    // this->occupancyTable = new OccupancyTable(this);


    if (testing) {
	Region* r = new Region(0,0,allCountries[0]);
    // //TODO: Check position is not already taken
	regions.emplace(r->getUUID(), r);
	r = new Region(49,24,allCountries[0]);
	regions.emplace(r->getUUID(), r);
	r = new Region(30,10,allCountries[1]);
	regions.emplace(r->getUUID(), r);
    } else {
	//Initialize travel difficulty field to 0's
	this->randomInitializeRegions(this->numRegions, allCountries);
    }

    //Create travel difficulty fields
    this->travelDifficultyField_allianceA = new float*[mapW];
    this->travelDifficultyField_allianceB = new float*[mapW];
    for(int x = 0; x < mapW; x++)
    {
        this->travelDifficultyField_allianceA[x] = new float[mapH];
        this->travelDifficultyField_allianceB[x] = new float[mapH];
    }

    this->recalculateTravelFields();
}

//Call this whenever the outcome of a battle changes a Region's occupancy
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

void Map::randomInitializeRegions(int numRegions, std::vector<Country*> allCountries)
{
    if(allCountries.size() == 0) { return; } //No countries, therefore cannot make regions
    for(auto r = this->regions.begin(); r != this->regions.end(); r++) { delete r->second; } //Delete any old regions

    //Randomly initialize regions
    this->regions = std::map<UUID, Region*>();

    std::set<MapCoords> coords;

    //Insert regions in such a way that no two regions have the same coordinates
    for(int i = 0; i < numRegions; i++)
    {
        MapCoords toTryInsert = { uuid::randomInt(0, 49), uuid::randomInt(0, 24) };

        while(coords.count(toTryInsert)) //While there is a collision
        {
            toTryInsert = {uuid::randomInt(0, 49), uuid::randomInt(0, 24)};
        }
        coords.insert(toTryInsert);

        Country* possessor = allCountries[uuid::randomInt(0, allCountries.size()-1)];

        Region* r = new Region(toTryInsert.x, toTryInsert.y, possessor);
        regions.emplace(r->getUUID(), r);
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

int dist(MapCoords a, MapCoords b)
{
    int dx = a.x-b.x;
    int dy = a.y-b.y;

    return sqrt(dx*dx + dy*dy);
}

float sumLineLow(int x0, int y0, int x1, int y1, scalarField2D field)
{
    float res = 0;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    int D = (2 * dy) - dx;
    int y = y0;

    for(int x = x0; x <= x1; x++)
    {
        res += field[x][y];
        if (D > 0)
        {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }
        else
        {
            D = D + 2*dy;
        }
    }
    return res;
}

float sumLineHigh(int x0, int y0, int x1, int y1, scalarField2D field)
{
    float res = 0;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = x0;

    for(int y = y0; y <= y1; y++)
    {
        res += field[x][y];
        if (D > 0)
        {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
        {
            D = D + 2*dx;
        }
    }
    return res;
}

float sumBrensenhamLine(int x0, int y0, int x1, int y1, scalarField2D field)
{
    float sum = 0;

    if (std::abs(y1 - y0) < std::abs(x1 - x0))
    {
        if (x0 > x1) { sum += sumLineLow(x1, y1, x0, y0, field); }
        else { sum += sumLineLow(x0, y0, x1, y1, field); }
    }
    else
    {
        if (y0 > y1) { sum += sumLineHigh(x1, y1, x0, y0, field); }
        else { sum += sumLineHigh(x0, y0, x1, y1, field); }
    }
    return sum;
}

//Get a measure of the difficulty for a country from teamA/teamB to travel linearly between two points on the map
float Map::getTravelDifficulty(MapCoords from, MapCoords to, bool teamA)
{
    scalarField2D field = teamA ? travelDifficultyField_allianceA : travelDifficultyField_allianceB;
    if(from.x == to.x && from.y == to.y) { return 0; }
    return sumBrensenhamLine(from.x, from.y, to.x, to.y, field) + dist(from, to)*0.1;
}

MapMemento* Map::makeMemento()
{
    HeightMap hm = {
        this->travelDifficultyField_allianceA,
        this->travelDifficultyField_allianceB
    };
    return new MapMemento(hm);
}
void Map::setMemento(MapMemento* mem){
    this->travelDifficultyField_allianceA = mem->getState()->travelFieldA;
    this->travelDifficultyField_allianceB = mem->getState()->travelFieldB;
    delete mem; // this is fine becuase it is a stack and the recieved memento should not be accessed again
}

Map::~Map()
{
    // For some reason it seems to be dealocating itself
    //Deallocate travel fields
    // for(int x = 0; x < mapW; x++)
    // {
        // delete [] this->travelDifficultyField_allianceA[x];
        // delete [] this->travelDifficultyField_allianceB[x];
    // }
    // delete [] this->travelDifficultyField_allianceA;
    // delete [] this->travelDifficultyField_allianceA;
}
