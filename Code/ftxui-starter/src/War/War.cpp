#include "War.h"

#include "Conflict.h"

War::War() {
  this->warPhase = new Conflict();
  teamA = new Alliance("Side A");
  teamB = new Alliance("Side B");
  // map = new Map();
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
}