#pragma once 
#include "WarPhase.h"
#include "DisputeSettled.h"

class PostWar : public WarPhase{
 public:
  PostWar();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};