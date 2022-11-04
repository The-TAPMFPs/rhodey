#pragma once
#include "Region.h"
#include "../Entities/Entity.h"
#include "Map.h"
#include <map>

struct RegionToEntities {
    std::vector<Entity *> entities;
};

class OccupancyTable {
    private:
	map<UUID, Region *> entityToRegion;
	map<UUID, RegionToEntities*> regionToEntties;
    public:
	OccupancyTable(Map * );
	~OccupancyTable();
	Region * addEntity(Entity *, Region *);
	std::vector<Entity *> getEntities(Region *);
	std::vector<Entity *> getEntities(UUID region);
	Region * getRegion(Entity *);
	Region * getRegion(UUID entity);
};
