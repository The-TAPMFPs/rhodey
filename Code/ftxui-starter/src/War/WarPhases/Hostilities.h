#pragma once
#include "WarPhase.h"

class Hostilities : public WarPhase {
 public:
  Hostilities();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};