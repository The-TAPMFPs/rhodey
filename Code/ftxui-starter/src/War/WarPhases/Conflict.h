#pragma once
#include "WarPhase.h"
#include "PostWar.h"

class Conflict : public WarPhase {
 public:
  Conflict();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};