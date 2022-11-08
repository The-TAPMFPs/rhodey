#pragma once
#include "WarPhase.h"

class Conflict : public WarPhase {
 public:
  Conflict();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};