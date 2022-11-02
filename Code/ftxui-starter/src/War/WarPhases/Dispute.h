#pragma once
#include "WarPhase.h"
#include "Hostilities.h"

class Dispute : public WarPhase {
 public:
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};