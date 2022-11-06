#pragma once
#include "WarPhase.h"
#include "Hostilities.h"

class Dispute : public WarPhase {
 public:
  Dispute();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};