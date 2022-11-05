#include "MapCaretaker.h"

void MapCaretaker::addMemento(MapMemento* mem) {
  list.push_back(mem);
}
MapMemento* MapCaretaker::removeMemento() {
  MapMemento* mem = (list.size() == 0 ? nullptr : list.back());
  if (mem != NULL) {
    list.pop_back();
  }
  return mem;
}
