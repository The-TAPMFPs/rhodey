#pragma once
#include "WarPhase.h"
#include "Conflict.h"

class Hostilities : public WarPhase {
 public:
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};