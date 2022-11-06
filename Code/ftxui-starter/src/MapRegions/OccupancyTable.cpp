#include "OccupancyTable.h"
#include <map>
#include <utility>
#include <vector>

OccupancyTable::OccupancyTable(Map * InitialMap ) {
    std::map<UUID, Region *>::iterator i;
    for (i = InitialMap->regions.begin(); i!=InitialMap->regions.end(); ++i) {
	i->second->getUUID();
	RegionToEntities * newGroup = new RegionToEntities();
	this->regionToEntties.insert(
		pair<UUID, RegionToEntities *>(i->first,newGroup));
    }
    this->globalMap = InitialMap;
}

OccupancyTable::~OccupancyTable() {
    std::map<UUID, RegionToEntities *>::iterator i;
    for (i = this->regionToEntties.begin(); i!=this->regionToEntties.end(); ++i) {
	delete i->second;
    }
}
Region * OccupancyTable::addEntity(Entity * entity, Region * region)  {
    std::vector<Entity *> current = this->getEntities(region);
    for (auto itr = current.begin(); itr != current.end(); ++itr) {
	if (*itr == entity) {
	    return region;
	}
    }

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

bool OccupancyTable::moveEntity(Entity * entity, Region * region) {
    Region * currentlocation = this->getRegion(entity);
    bool player = entity->getCountry()->getAlliance()->isPlayer();
    int difficulty = this->globalMap->getTravelDifficulty(
	    currentlocation->getCoords(), region->getCoords(), player);

    double proportionToTransport = float(entity->getTerrainHandling())/difficulty;
    int numberToTransport = entity->getAmount()*proportionToTransport + 10;

    // if we can transport all of them
    if (numberToTransport > entity->getAmount()) {
	this->entityToRegion.at(entity->getUUID()) = region;
	this->regionToEntties.at(region->getUUID())->entities.push_back(entity);
	vector<Entity *> entityAtRegion = this->regionToEntties.at(
		currentlocation->getUUID())->entities;
	for (auto itr = entityAtRegion.begin(); itr != entityAtRegion.end();
		++itr) {
	    if (*itr == entity) {
		entityAtRegion.erase(itr);
		return true;
	    }
	}
    }

    // if there is not enough to transport all of them
    Entity * splitGroup = entity->split(numberToTransport);
    this->addEntity(splitGroup, region);
    return false;
}

bool OccupancyTable::moveEntity(vector<Entity *> entities, Region * region) {
    // check no opposing factions and simulatiously
    // get average transport effectiveness
    // Calculate carying capacity
    Alliance * firstAlliance = entities.at(0)->getCountry()->getAlliance();
    Region * currentlocation = this->getRegion(entities.at(0));
    int avg = 0; // Average Travel Effectiveness
    int capacity = 0;
    int total = 0; // total units
    for (auto itr = entities.begin(); itr != entities.end(); ++itr) {
	avg += (*itr)->getTerrainHandling();
	capacity += (*itr)->getCarryingCapacity();
	total += (*itr)->getAmount();
	if (((*itr)->getCountry()->getAlliance() != firstAlliance) ||
		this->entityToRegion.at((*itr)->getUUID())!=currentlocation) {
	    /* TODO: Make new Exception  <05-11-22, yourname> */
	    throw exception();
	}
    }

    int difficulty = this->globalMap->getTravelDifficulty(
	    currentlocation->getCoords(), region->getCoords(),
	    firstAlliance->isPlayer());

    avg = avg/entities.size();
    double amoutToTransport = double(capacity)/double(total);
    double distanceModify = float(avg)/difficulty;
    amoutToTransport = amoutToTransport * distanceModify;
    if (amoutToTransport >= 1) {
	for (auto entity = entities.begin(); entity != entities.end(); ++entity) {
	    this->entityToRegion.at((*entity)->getUUID()) = region;
	    this->regionToEntties.at(region->getUUID())->entities.push_back(*entity);
	    vector<Entity *> entityAtRegion = this->regionToEntties.at(
		    currentlocation->getUUID())->entities;
	    for (auto itr = entityAtRegion.begin(); itr != entityAtRegion.end();
		    ++itr) {
		if (*itr == *entity) {
		    entityAtRegion.erase(itr);
		    return true;
		}
	    }
	}
    }

    for (auto entity = entities.begin(); entity != entities.end(); ++entity) {
	Entity * splitGroup = (*entity)->split((*entity)->getAmount()*amoutToTransport);
	this->addEntity(splitGroup, region);
	return false;
    }

    return false;
}
