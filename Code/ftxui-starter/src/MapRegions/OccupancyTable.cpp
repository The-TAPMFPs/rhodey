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
#include "Entities/Entity.h"
#include "Entities/Troop/Troop.h"
#include "Entities/Vehicle/Vehicle.h"

/**
  * \fn OccupancyTable::OccupancyTable(Map * InitialMap )
  * \brief Constructs a New OccupancyTable.
  * @param InitialMap A pointer to the map that the OccupancyTable must be initialized to.
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


/**
  * \fn OccupancyTable::~OccupancyTable()
  * \brief Deletes the OccupancyTable along with all Entities contained within it.
  */
OccupancyTable::~OccupancyTable() {
    std::map<UUID, RegionToEntities *>::iterator i;
    for (i = this->regionToEntties.begin(); i!=this->regionToEntties.end(); ++i) {
	for (auto itr = i->second->entities.begin(); itr != i->second->entities.end(); ++itr) {
	    delete *itr;
	}
	i->second->entities.clear();
    }

}

/**
  * \fn OccupancyTable::addEntity(Entity * entity, Region * region)
  * \brief Adds a Entity to a Region in the simulation
  * @param entity The entity to be added.
  * @param region The region to which the entity must be added to.
  * @return return the region that the entity was added to. Return is null if entity was not added.
  */
Region * OccupancyTable::addEntity(Entity * entity, Region * region)  {
    std::vector<Entity *> current = this->getEntities(region); /** current entities at this location */
    for (auto itr = current.begin(); itr != current.end(); ++itr) {
	if (*itr == entity) {
	    return region;
	}
	if ((*itr)->getName() == entity->getName()) {
	    try {
		(*itr)->absorb(entity);
	    }catch(WrongType e) {
		continue;
	    } catch(SameEntity e) {
		return NULL; /** This should never happen. */
	    } catch(DifferentAlliances e) {
		continue;
	    }
	    return region;
	}
    }

    this->entityToRegion.insert(pair<UUID, Region *>(entity->getUUID(),region)); /** Insert new Entity into Entity to region map*/
    this->regionToEntties.at(region->getUUID())->entities.push_back(entity);/** Add entity to list of entities at the region*/
    return region;
}

/**
  * \fn OccupancyTable::getEntities(Region * region)
  * \brief Returns the entities at a region.
  * @param region The region to get the entities at.
  * @return Returns a vector of entities that are located at that region.
  */
std::vector<Entity *> OccupancyTable::getEntities(Region * region) {
    vector<Entity *> initVector = this->regionToEntties.at(region->getUUID())->entities;
    std::vector<Entity *> newvector; /** The vector to return. We don't clean the OccupancyTable because its a resourse intensive task */
    for (int count = 0; count < initVector.size(); count++) {
	// return only living entities
	if (initVector[count]->getAmount() > 0) { /** Return only entities that are alive*/
	    newvector.push_back(initVector[count]);
	}
    }
    return newvector;
}

/**
  * \fn OccupancyTable::cleanUp()
  * \brief Removes any dead entities from the OccupancyTable.
  */
void OccupancyTable::cleanUp() {
    for (auto outer = this->regionToEntties.begin(); outer != this->regionToEntties.end(); ++outer) { /** Go through each region*/
	for (int itr = 0; itr < outer->second->entities.size(); ++itr) { /** Go through all the entities at that region */
	    if (outer->second->entities[itr]->getAmount() <= 0) { /** Remove the entitiy if it is dead */
		auto todelete = this->entityToRegion.find(outer->second->entities[itr]->getUUID());
		this->entityToRegion.erase(todelete);
		delete outer->second->entities.at(itr);
		outer->second->entities.erase(outer->second->entities.begin() + itr);
	    }
	}
    }
}

/**
  * \fn OccupancyTable::getEntities(UUID region)
  * \brief Gets the entities at a region using the regions UUID.
  * @param region The UUID of the region to get the entities from.
  * @return Returns the Entities at the specified region.
  */
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


/**
  * \fn OccupancyTable::getRegion(Entity * entity)
  * \brief Returns the region that a entity is associated with.
  * @param entity The entity that we want to find the associated region for.
  * @return Return the associated region of the specified entity.
  */
Region * OccupancyTable::getRegion(Entity * entity) {
    return this->entityToRegion.at(entity->getUUID());
}

/**
  * \fn OccupancyTable::getRegion(UUID entity)
  * \brief Returns the region that a entity is associated with.
  * @param entity The entitys UUID that we want to find the associated region for.
  * @return Return the associated region of the specified entity.
  */
Region * OccupancyTable::getRegion(UUID entity) {
    return this->entityToRegion.at(entity);
}

/**
  * \fn OccupancyTable::moveEntity(Entity * entity, Region * region)
  * \brief Moves a single entity to a specified region.
  * @param entity The entity to move.
  * @param region The region to move the specified entity to
  * @return Return true if the entity was moved and false if the entity was not.
  */
bool OccupancyTable::moveEntity(Entity * entity, Region * region) {
    Region * currentlocation = this->getRegion(entity);
    if (long(currentlocation) == long(region)) { /** Check if the current location is the region that we are asked to move to */
	return true;
    } else if (entity->getAmount() <= 0) {
	return false;
    }
    bool player = entity->getCountry()->getAlliance()->isTeamA(); /** Get boolean value of what alliance we are part of. */
    float difficulty = this->globalMap->getTravelDifficulty(
	    currentlocation->getCoords(), region->getCoords(), player); /** Return the difficulty value of the location we are trying to travel to */

    double proportionToTransport = float(entity->getTerrainHandling())/difficulty; /** Gets a ratio of how much we can transport based on the level of difficulty to traverse the terrain and our own capability of traversing terrain */
    float numberToTransport = (float(entity->getCarryingCapacity())/entity->getAmount())*proportionToTransport; /** Get the total proportion of entities that we want to transport */

    if (numberToTransport >= 1) { /** If we can transport all the entities then do not split */
	this->entityToRegion.at(entity->getUUID()) = region;
	this->regionToEntties.at(region->getUUID())->entities.push_back(entity);

	std::vector<Entity *> mergeing = this->regionToEntties.at(region->getUUID())->entities;
	for (auto itr = mergeing.begin(); itr != mergeing.end(); ++itr) { /** Merge with all the entities that have the same name as us*/
	    if ((*itr)->getName() == entity->getName()) {
		try {
		    entity->absorb(*itr);
		}catch(WrongType e) {
		    continue;
		} catch(SameEntity e) {
		    throw exception(); /** This should never happen. */
		} catch(DifferentAlliances e) {
		    continue;
		}
	    }
	}

	vector<Entity *> * entityAtRegion = &(this->regionToEntties.at(
		currentlocation->getUUID())->entities);
	for (auto itr = entityAtRegion->begin(); itr != entityAtRegion->end();
		++itr) { /** Remove any dangling references to the entity we moved in its previous location */
	    if (long(*itr) == long(entity)) {
		entityAtRegion->erase(itr);
		return true;
	    }
	}
    }

    Entity * splitGroup = entity->split(int(numberToTransport*entity->getAmount())); /** If we cant transport all of the entities then we can just split them up and transport some of them */
    this->addEntity(splitGroup, region);
    return false;
}

/**
  * \fn OccupancyTable::moveEntity(vector<Entity *> entity, Region * region)
  * \brief Moves a group of entities to a specified region.
  * @param entities The entities to move.
  * @param region The region to move the specified entity to
  * @return Return true if the entity was moved and false if the entity was not.
  */
bool OccupancyTable::moveEntity(vector<Entity *> entities, Region * region) {
    Alliance * firstAlliance = entities.at(0)->getCountry()->getAlliance(); /** Used to check if all entities are in the same alliance */
    Region * currentlocation = this->getRegion(entities.at(0)); /** Used to check if all locations are the same*/
    int avg = 0; // Average Travel Effectiveness
    int capacity = 0;
    int total = 0; // total units
    for (auto itr = entities.begin(); itr != entities.end(); ++itr) {
	avg += (*itr)->getTerrainHandling();
	capacity += (*itr)->getCarryingCapacity();
	total += (*itr)->getAmount();
	if (((*itr)->getCountry()->getAlliance() != firstAlliance) ||
		this->entityToRegion.at((*itr)->getUUID())!=currentlocation) { /** Check if we have differning regions or entities*/
	    throw IncompatibleMove();
	}
    }

    if (currentlocation == region) {
	return true;
    }

    bool firstAlly = firstAlliance->isTeamA();
    float difficulty = this->globalMap->getTravelDifficulty(
	    currentlocation->getCoords(), region->getCoords(), firstAlly); /** Return the difficulty value of the location we are trying to travel to */

    avg = avg/entities.size(); /** Get the average terrain difficulty traversal */
    double proportionOfTransport = double(capacity)/double(total); /**A ratio that affects how effectively troops can be at moving in a group*/
    double distanceModify = float(avg)/difficulty;/** Gets a ratio of how much we can transport based on the level of difficulty to traverse the terrain and our own capability of traversing terrain */
    double amoutToTransport = proportionOfTransport * distanceModify;/** Get the total proportion of entities that we want to transport */


    if (amoutToTransport >= 1) {/** If we can transport all the entities then do not split */
	// for each entity in those we need to add
	for (auto entity = entities.begin(); entity != entities.end(); ++entity) { /** For each Entity that we need to move*/
	    this->entityToRegion.at((*entity)->getUUID()) = region;
	    this->regionToEntties.at(region->getUUID())->entities.push_back(*entity);

	    // Loop through new region and absorb troops that need to
	    std::vector<Entity *> regionEntityArray =
		this->regionToEntties.at(region->getUUID())->entities;
	    for (auto itr = regionEntityArray.begin();
		    itr != regionEntityArray.end(); ++itr) {/** Merge with all the entities that have the same name as us*/
		if ((*itr)->getName() == (*entity)->getName()) {
		    try {
			(*entity)->absorb(*itr);
		    }catch(WrongType e) {
			continue;
		    } catch(SameEntity e) {
			throw exception(); /** This should never happen. */
		    } catch(DifferentAlliances e) {
			continue;
		    }
			break;
		}
	    }

	    // cleanUp
	    vector<Entity *> * entityAtRegion = &this->regionToEntties.at(
		    currentlocation->getUUID())->entities;
	    for (auto itr = entityAtRegion->begin(); itr != entityAtRegion->end();
		    ++itr) { /** Remove any dangling references to the entity we moved in its previous location */
		if (*itr == *entity) {
		    entityAtRegion->erase(itr);
		    break;
		}
	    }
	}
	return true;
    }

    for (auto entity = entities.begin(); entity != entities.end(); ++entity) {/** If we cant transport all of the entities then we can just split them up and transport some of them */

	Entity * splitGroup = (*entity)->split((*entity)->getAmount()*amoutToTransport);
	this->addEntity(splitGroup, region);
    }

    return false;
}

int OccupancyTable::getNumTroops(Country * country) {
    int total = 0;
    for (auto itr = this->regionToEntties.begin(); itr != this->regionToEntties.end(); ++itr) {
	std::vector<Entity *> entityVector = itr->second->entities;
	for (auto entity = entityVector.begin(); entity != entityVector.end(); ++entity) {
	    if (long((*entity)->getCountry()) == long(country)) {
		Troop * troopCast = dynamic_cast<Troop*>((*entity));
		if (troopCast != NULL) {
		    total += troopCast->getAmount();
		}
	    }
	}
    }
    return total;
}

int OccupancyTable::getNumVehicles(Country * country) {
    int total = 0;
    for (auto itr = this->regionToEntties.begin(); itr != this->regionToEntties.end(); ++itr) {
	std::vector<Entity *> entityVector = itr->second->entities;
	for (auto entity = entityVector.begin(); entity != entityVector.end(); ++entity) {
	    if (long((*entity)->getCountry()) == long(country)) {
		if ((*entity)->isVehicle()) {
		    total += (*entity)->getAmount();
		}
	    }
	}
    }
    return total;
}
