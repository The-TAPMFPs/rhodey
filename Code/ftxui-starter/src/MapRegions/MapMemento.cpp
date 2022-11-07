/**
 * \file MapMemento.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */
#include "MapMemento.h"

/**
 * \fn MapMemento::MapMemento(HeightMap hm)
 * \brief creates a new MapMemento initialized with HeightMap data
 * \param a object of type HeightMap
 * 
*/
MapMemento::MapMemento(HeightMap hm){
    this->hm = new HeightMap(hm);
}
/**
 * \fn MapMemento::~MapMemento()
 * \brief destructor for the MapMemento, deletes heightMap data 
 * 
*/
MapMemento::~MapMemento()
{
    delete hm;
}
/**
 * \fn HeightMap* MapMemento::getState()
 * \brief function that gets the state of the height map
 * \return the new heightMap data
*/
HeightMap* MapMemento::getState() {
    return hm;
}
/**
 * \fn void MapMemento::setState(HeightMap hm)
 * \brief sets the state of the memento with the passed in param
 * \param hm an object of type heightmap 
*/
void MapMemento::setState(HeightMap hm) {
    this->hm = &hm;
}
