/**
 * \file MapCaretaker.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */

#include "MapCaretaker.h"

/**
 * \fn MapCaretake::addMemento (MapMemento* mem)
 * \brief function that adds MapMemento to a vector 
 * \param mem the memento to be added to the caretaker
*/
void MapCaretaker::addMemento(MapMemento* mem) {
  list.push_back(mem);
}

/**
 * \fn MapMemento* MapCaretaker::removeMemento ()
 * \brief a function that removes a memento from the vector storing MapMementos
 * \return the memento removed from the caretaker. Returns null if there is none
*/
MapMemento* MapCaretaker::removeMemento() {
  MapMemento* mem = (list.size() == 0 ? nullptr : list.back());/**a pointer to the MapMemento that will be removed from the vector */
  if (mem != NULL) {
    list.pop_back();
  }
  return mem;
}
