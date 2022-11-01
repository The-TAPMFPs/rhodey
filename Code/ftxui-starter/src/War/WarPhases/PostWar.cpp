#include "PostWar.h"

void PostWar::handleWarChange(War* war) {
  war->transitionTo(new DisputeSettled());
}

std::string PostWar::getCurrentWarState() {
  return "Currently in Postwar State";
}