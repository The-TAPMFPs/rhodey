#include "MapMemento.h"

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
