#pragma once
#include "WarPhase.h"

class DisputeSettled : public WarPhase {
 public:
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};