#include "MapCaretaker.h"

void MapCaretaker::addMemento(MapMemento* mem) {
  list.push_back(mem);
}
MapMemento* MapCaretaker::removeMemento() {
  return list.size() == 0 ? NULL : list.at(list.size());
}
