#include "OccupancyTable.h"
#include <map>
#include <utility>
#include <vector>

OccupancyTable::OccupancyTable(Map * InitialMap ) {
    std::map<UUID, Region *>::iterator i;
    for (i = InitialMap->regions.begin(); i!=InitialMap->regions.end(); ++i) {
	RegionToEntities * newGroup = new RegionToEntities();
	this->regionToEntties.insert(
		pair<UUID, RegionToEntities *>(i->first,newGroup));
    }
}

OccupancyTable::~OccupancyTable() {
    std::map<UUID, RegionToEntities *>::iterator i;
    for (i = this->regionToEntties.begin(); i!=this->regionToEntties.end(); ++i) {
	delete i->second;
    }
}
Region * OccupancyTable::addEntity(Entity * entity, Region * region)  {
    this->entityToRegion.insert(pair<UUID, Region *>(entity->getUUID(),region));
    this->regionToEntties.at(region->getUUID())->entities.push_back(entity);
    return region;
}

std::vector<Entity *> OccupancyTable::getEntities(Region * region) {
    vector<Entity *> initVector = this->regionToEntties.at(region->getUUID())->entities;
    std::vector<Entity *> newvector;
    for (int count = 0; count < initVector.size(); count++) {
	// return only living entities
	if (initVector[count]->getAmount() > 0) {
	    newvector.push_back(initVector[count]);
	}
    }
    return newvector;
}


std::vector<Entity *> OccupancyTable::getEntities(UUID region) {
    vector<Entity *> initVector = this->regionToEntties.at(region)->entities;
    std::vector<Entity *> newvector;
    for (int count = 0; count < initVector.size(); count++) {
	// return only living entities
	if (initVector[count]->getAmount() > 0) {
	    newvector.push_back(initVector[count]);
	}
    }
    return newvector;
}


Region * OccupancyTable::getRegion(Entity * entity) {
    return this->entityToRegion.at(entity->getUUID());
}

Region * OccupancyTable::getRegion(UUID entity) {
    return this->entityToRegion.at(entity);
}
