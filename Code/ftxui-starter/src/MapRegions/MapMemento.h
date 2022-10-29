#pragma once
#include "Map.h"

struct MapData;

class MapMemento
{
    private:
        MapData* md;
        MapData* getState();
        MapData* setState();
        friend class Map;
    public:
        MapMemento(MapData*);
        virtual ~MapMemento();
        
};