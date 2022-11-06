#include "MapMemento.h"

/**
 * \fn MapMemento::~MapMemento ()
 * \brief deletes the map memento member
*/
MapMemento::~MapMemento()
{
    delete md;
}

/**
 * \fn MapMemento::MapMemento (MapData md)
 * \brief creates new MapMemento 
 * \param md the map data to be stored in the memento
 * 
*/
MapMemento::MapMemento(MapData md){
    this->md = &md;
}

/**
 *\fn MapData* MapMemnto::getState ()
 * \brief gets the state of the currently stored memento
 * \return the map data pointer stored in the memento
*/
MapData* MapMemento::getState() {
    return md;
}


/**
 * \fn void MapMemento::setState (MapData md)
 * \brief sets the state of the new memento
 * \param md the map data to be stored in the memento
*/
void MapMemento::setState(MapData md) {
    this->md = &md;
}
