#include "Dispute.h"

void Dispute::handleWarChange(War* war) {
  war->transitionTo(new Hostilities());
}

std::string Dispute::getCurrentWarState() {
  return "Currently in Dispute State";
}