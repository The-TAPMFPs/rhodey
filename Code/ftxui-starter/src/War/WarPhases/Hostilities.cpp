#include "Hostilities.h"

Hostilities::Hostilities() {
  War::warState = "Hostilities";
  War::warStateDesc = "Currently in Hostilities, Sim will start Now <- This should be changed";
}

void Hostilities::handleWarChange(War* war) {
  war->transitionTo(new Conflict());
}

std::string Hostilities::getCurrentWarState() {
  return "Currently in Hostilities State";
}