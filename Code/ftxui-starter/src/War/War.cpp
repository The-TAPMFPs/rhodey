#include "War.h"

#include "Conflict.h"

War::War() {
  this->warPhase = new Conflict();
  teamA = new Alliance("Side A");
  teamB = new Alliance("Side B");

  //TODO: Replace with properly initialized data
  teamA->add(new Country("country A"));
  teamA->add(new Country("country B"));
  teamA->add(new Country("country C"));
  teamA->add(new Country("country D"));
  teamB->add(new Country("country E"));
  teamB->add(new Country("country F"));
  teamB->add(new Country("country G"));
  teamB->add(new Country("country H"));

  map = new Map();
}

War::~War() {
  delete warPhase;
  delete teamA, teamB;
}

void War::transitionTo(WarPhase* warPhase) {
  if (warPhase != NULL)
    delete warPhase;
  this->warPhase = warPhase;
}

void War::addCountryToSideA(Country* country) {
  teamA->add(country);
}

void War::addCountryToSideB(Country* country) {
  teamB->add(country);
}

void War::changeState() {
  warPhase->handleWarChange(this);
}

void War::start() {
  teamA->print();
  teamB->print();
  // TODO start the war
}

MapData War::getCurrentMapData()
{
  return this->map->getCurrentMapData();
}