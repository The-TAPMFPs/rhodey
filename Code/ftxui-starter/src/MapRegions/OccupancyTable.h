#pragma once
#include "Region.h"
#include "../Entities/Entity.h"
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
};
