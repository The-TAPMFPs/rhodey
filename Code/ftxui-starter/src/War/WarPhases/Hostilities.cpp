#include "Hostilities.h"

void Hostilities::handleWarChange(War* war) {
  war->transitionTo(new Conflict());
}

std::string Hostilities::getCurrentWarState() {
  return "Currently in Hostilities State";
}