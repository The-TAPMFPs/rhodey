#include "Conflict.h"

void Conflict::handleWarChange(War* war) {
  war->transitionTo(new PostWar());
}

std::string Conflict::getCurrentWarState() {
  return "Currently in Conflict State";
}