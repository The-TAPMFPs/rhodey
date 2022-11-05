#pragma once
#include "WarPhase.h"

class DisputeSettled : public WarPhase {
 public:
  DisputeSettled();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};