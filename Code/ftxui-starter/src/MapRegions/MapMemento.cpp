#include "MapMemento.h"

/**
 * \fn MapMemento::~MapMemento ()
 * deletes the map memento member
*/
MapMemento::~MapMemento()
{
    delete md;
}

/**
 * \fn MapMemento::MapMemento (MapData md)
 * 
 * \param md the map data to be stored in the memento
*/
MapMemento::MapMemento(MapData md){
    this->md = &md;
}

/**
 *\fn MapData* MapMemnto::getState ()

 * \return the map data pointer stored in the memento
*/
MapData* MapMemento::getState() {
    return md;
}


/**
 * \fn void MapMemento::setState (MapData md)
 * 
 * \param md the map data to be stored in the memento
*/
void MapMemento::setState(MapData md) {
    this->md = &md;
}
MapMemento::MapMemento(HeightMap hm){
    this->hm = new HeightMap(hm);
}

MapMemento::~MapMemento()
{
    //delete hm;
}

HeightMap* MapMemento::getState() {
    return hm;
}

void MapMemento::setState(HeightMap hm) {
    this->hm = &hm;
}
