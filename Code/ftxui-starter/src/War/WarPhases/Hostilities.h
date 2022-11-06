#pragma once
#include "WarPhase.h"
#include "Conflict.h"

class Hostilities : public WarPhase {
 public:
  Hostilities();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};