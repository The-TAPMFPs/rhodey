#include "War.h"

War::War() {
  teamA = new Alliance("Side A");
  teamB = new Alliance("Side B");
  map = new Map();
}

void War::addCountryToSideA(Country* country) {
  teamA->add(country);
}

void War::addCountryToSideB(Country* country) {
  teamB->add(country);
}

void War::start() {
  teamA->print();
  teamB->print();
  // TODO start the war
}