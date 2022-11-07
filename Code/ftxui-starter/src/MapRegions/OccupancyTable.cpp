/**
 * \file OccupancyTable.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
#include "OccupancyTable.h"
#include <exception>
#include <map>
#include <utility>
#include <vector>
/**
 * \fn OccupancyTable::OccupancyTable(Map * InitialMap )
 * \brief 
*/
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
	for (auto itr = i->second->entities.begin(); itr != i->second->entities.end(); ++itr) {
	    delete *itr;
	}
	i->second->entities.clear();
    }

}
Region * OccupancyTable::addEntity(Entity * entity, Region * region)  {
    std::vector<Entity *> current = this->getEntities(region);
    for (auto itr = current.begin(); itr != current.end(); ++itr) {
	if (*itr == entity) {
	    return region;
	}
	if ((*itr)->getName() == entity->getName()) {
	    (*itr)->absorb(entity);
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
    if (long(currentlocation) == long(region)) {
	return true;
    } else if (entity->getAmount() <= 0) {
	return false;
    }
    bool player = entity->getCountry()->getAlliance()->isTeamA();
    float difficulty = this->globalMap->getTravelDifficulty(
	    currentlocation->getCoords(), region->getCoords(), player);

    double proportionToTransport = float(entity->getTerrainHandling())/difficulty;
    float numberToTransport = entity->getAmount()*proportionToTransport + 10;

    // if we can transport all of them
    if (numberToTransport >= entity->getAmount()) {
	this->entityToRegion.at(entity->getUUID()) = region;
	this->regionToEntties.at(region->getUUID())->entities.push_back(entity);

	std::vector<Entity *> mergeing = this->regionToEntties.at(region->getUUID())->entities;
	for (auto itr = mergeing.begin(); itr != mergeing.end(); ++itr) {
	    if ((*itr)->getName() == entity->getName()) {
		entity->absorb(*itr);
	    }
	}

	vector<Entity *> * entityAtRegion = &(this->regionToEntties.at(
		currentlocation->getUUID())->entities);
	for (auto itr = entityAtRegion->begin(); itr != entityAtRegion->end();
		++itr) {
	    if (long(*itr) == long(entity)) {
		entityAtRegion->erase(itr);
		return true;
	    }
	}
    }

    // if there is not enough to transport all of them
    Entity * splitGroup = entity->split(int(numberToTransport));
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

    bool firstAlly = firstAlliance->isTeamA();
    float difficulty = this->globalMap->getTravelDifficulty(
	    currentlocation->getCoords(), region->getCoords(), firstAlly);

    avg = avg/entities.size();
    double amoutToTransport = double(capacity)/double(total);
    double distanceModify = float(avg)/difficulty;
    amoutToTransport = amoutToTransport * distanceModify;


    if (amoutToTransport >= 1) {
	// for each entity in those we need to add
	for (auto entity = entities.begin(); entity != entities.end(); ++entity) {
	    // set new region
	    this->entityToRegion.at((*entity)->getUUID()) = region;
	    this->regionToEntties.at(region->getUUID())->entities.push_back(*entity);

	    // Loop through new region and absorb troops that need to
	    std::vector<Entity *> regionEntityArray =
		this->regionToEntties.at(region->getUUID())->entities;
	    for (auto itr = regionEntityArray.begin();
		    itr != regionEntityArray.end(); ++itr) {
		if ((*itr)->getName() == (*entity)->getName()) {
		    (*entity)->absorb(*itr);
		    break;
		}
	    }

	    // cleanUp
	    vector<Entity *> * entityAtRegion = &this->regionToEntties.at(
		    currentlocation->getUUID())->entities;
	    for (auto itr = entityAtRegion->begin(); itr != entityAtRegion->end();
		    ++itr) {
		if (*itr == *entity) {
		    entityAtRegion->erase(itr);
		    break;
		}
	    }
	}
	return true;
    }

    for (auto entity = entities.begin(); entity != entities.end(); ++entity) {
	Entity * splitGroup = (*entity)->split((*entity)->getAmount()*amoutToTransport);
	this->addEntity(splitGroup, region);
    }

    return false;
}
