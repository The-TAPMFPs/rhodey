#pragma once
#include "Map.h"

struct MapData;

class MapMemento
{
    private:
        MapData* md;
        MapData* getState();
        void setState();
        friend class MapCaretaker;
    public:
        MapMemento(MapData);
        virtual ~MapMemento();
        
};