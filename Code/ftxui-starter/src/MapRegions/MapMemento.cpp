#include "MapMemento.h"

MapMemento::~MapMemento()
{
    delete md;
}

MapMemento::MapMemento(MapData md){
    this->md = &md;
}

MapData* MapMemento::getState() {
    return md;
}

void MapMemento::setState(MapData md) {
    this->md = &md;
}
