#include "DisputeSettled.h"

void DisputeSettled::handleWarChange(War* war) {
  // Dont know what what state to transition to after War is done
  war->transitionTo(this);
}

std::string DisputeSettled::getCurrentWarState() {
  return "Currently in DisputeSettled State";
}