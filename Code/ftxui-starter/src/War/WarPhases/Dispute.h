#pragma once
#include "WarPhase.h"
#include "Hostilities.h"

<<<<<<< HEAD
class Dispute : public WarPhase{
    public:
        void DoSomething();
=======
class Dispute : public WarPhase {
 public:
  void handleWarChange(War* war);
  std::string getCurrentWarState();
>>>>>>> 41e7c89f6256f220eb5cfa2118e6eb30e74b7e36
};