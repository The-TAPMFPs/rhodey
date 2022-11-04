#include "MapMemento.h"

MapMemento::~MapMemento()
{
    delete md;
}
MapMemento::MapMemento(MapData md){
    this->md=&md;
}

Mapdata* MapMemento::getState(){
    return md;
}

void MapMemento::setState(Mapdata* md){
    this->md=md;
}
