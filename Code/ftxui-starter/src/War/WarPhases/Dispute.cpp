#include "Dispute.h"

Dispute::Dispute() {
  War::warState = "Dispute";
  War::warStateDesc = "The war in Asia began when Japan invaded China on July 7, 1937. The war began in Europe when Germany invaded Poland on September 1, 1939. France and the United Kingdom reacted by declaring war on Germany. By 1941, much of Europe was under German control, including France. Only the British remained fighting against the Axis in North Africa";
}

void Dispute::handleWarChange(War* war) {
  war->transitionTo(new Hostilities());
}

std::string Dispute::getCurrentWarState() {
  return "Currently in Dispute State";
}