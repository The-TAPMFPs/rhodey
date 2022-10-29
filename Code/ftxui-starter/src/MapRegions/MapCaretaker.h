#pragma once
#include <vector>
#include "MapMemento.h"

class MapCaretaker {
 private:
  std::vector<MapMemento*> list;

 public:
  void addMemento(MapMemento*);
  MapMemento* removeMemento();
};