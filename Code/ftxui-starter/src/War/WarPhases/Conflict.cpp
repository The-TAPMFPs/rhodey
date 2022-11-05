#include "Conflict.h"

Conflict::Conflict() {
  War::warState = "Conflict";
  War::warStateDesc = "Currently in Conflict State <- This should be changed";
}

void Conflict::handleWarChange(War* war) {
  war->transitionTo(new PostWar());
}

std::string Conflict::getCurrentWarState() {
  return "Currently in Conflict State";
}