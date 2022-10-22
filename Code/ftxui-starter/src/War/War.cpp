#include "War.h"

War::War(WarPhase* warPhase) : _warPhase(warPhase) {
  TransitionTo(warPhase);
}

void War::TransitionTo(WarPhase* warPhase) {
  if (_warPhase)
    delete _warPhase;
  _warPhase = warPhase;
  _warPhase->set_war(this);
}

War::~War() {
  delete _warPhase;
}

