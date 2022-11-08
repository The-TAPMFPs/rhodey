#pragma once 
#include "WarPhase.h"

class PostWar : public WarPhase{
 public:
  PostWar();
  void handleWarChange(War* war);
  std::string getCurrentWarState();
};