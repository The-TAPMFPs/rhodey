#pragma once
#include "Region.h"
#include "../Entities/Entity.h"
#include "../Country/Country.h"
#include "Map.h"
#include <map>

struct RegionToEntities {
    std::vector<Entity *> entities;
};

class Map;

class OccupancyTable {
    private:
	map<UUID, Region *> entityToRegion;
	map<UUID, RegionToEntities*> regionToEntties;
	Map * globalMap;
    public:
	OccupancyTable(Map * );
	~OccupancyTable();
	Region * addEntity(Entity *, Region *);
	std::vector<Entity *> getEntities(Region *);
	std::vector<Entity *> getEntities(UUID region);
	Region * getRegion(Entity *);
	Region * getRegion(UUID entity);
	bool moveEntity(Entity * entity, Region * region);
	bool moveEntity(vector<Entity *> entity, Region * region);
	int getNumTroops(Country *);
	int getNumVehicles(Country *);
	void cleanUp();
};


struct IncompatibleMove : public exception {
   const char * what () const throw () {
      return "The entities that you are trying to move together cannot be moved together.";
   }
};
