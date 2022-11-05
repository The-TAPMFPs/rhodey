#include "DisputeSettled.h"

DisputeSettled::DisputeSettled() {
  War::warState = "DisputeSettled";
  War::warStateDesc = "Currently in DisputeSettled State <- This should be changed";
}

void DisputeSettled::handleWarChange(War* war) {
  // transitions to null to screen loop
  war->transitionTo(NULL);
}

std::string DisputeSettled::getCurrentWarState() {
  return "Currently in DisputeSettled State";
}