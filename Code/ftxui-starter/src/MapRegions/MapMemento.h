#pragma once
#include "Map.h"

struct MapData;

class MapMemento
{
    private:
        MapData* md;
        MapMemento(MapData);
        virtual ~MapMemento();
        MapData* getState();
        void setState(MapData md);
        friend class Map;
};