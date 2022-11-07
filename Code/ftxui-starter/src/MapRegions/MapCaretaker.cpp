#include "MapCaretaker.h"

/**
 * \fn MapCaretake::addMemento (MapMemento* mem)
 * 
 * \param mem the memento to be added to the caretaker
*/
void MapCaretaker::addMemento(MapMemento* mem) {
  list.push_back(mem);
}

/**
 * \fn MapMemento* MapCaretaker::removeMemento ()
 * 
 * \return the memento removed from the caretaker. Returns null if there is none
*/
MapMemento* MapCaretaker::removeMemento() {
  MapMemento* mem = (list.size() == 0 ? nullptr : list.back());
  if (mem != NULL) {
    list.pop_back();
  }
  return mem;
}
