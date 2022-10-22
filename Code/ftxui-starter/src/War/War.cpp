#include "War.h"

War(WarPhase* warPhase) : _warPhase(warPhase) {
  TransitionTo(warPhase);
}

void TransitionTo(WarPhase* warPhase) {
  if (_warPhase)
    delete _warPhase;
  _warPhase = warPhase;
}

~War() {
  delete _warPhase;
}