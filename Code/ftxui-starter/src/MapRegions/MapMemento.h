#pragma once
#include "Map.h"

struct HeightMap;

class MapMemento
{
    public:
        ~MapMemento();
    private:
        HeightMap* hm;
        MapMemento(HeightMap md);
        HeightMap* getState();
        void setState(HeightMap md);
        friend class Map;
};