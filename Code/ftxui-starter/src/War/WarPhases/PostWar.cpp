#include "PostWar.h"

PostWar::PostWar() {
  War::warState = "PostWar";
  War::warStateDesc = "Currently in PostWar State <- This should be changed";
}

void PostWar::handleWarChange(War* war) {
  war->transitionTo(new DisputeSettled());
}

std::string PostWar::getCurrentWarState() {
  return "Currently in Postwar State";
}