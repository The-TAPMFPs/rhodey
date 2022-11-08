#pragma once
#include "WarPhase.h"

class Dispute : public WarPhase {
 public:
  Dispute();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};