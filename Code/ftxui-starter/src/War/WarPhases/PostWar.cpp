#include "PostWar.h"
#include "DisputeSettled.h"

PostWar::PostWar() {
  War::warState = "PostWar";
  War::warStateDesc = "Currently in PostWar State <- This should be changed";
  War::warStateThumbnailColor = ftxui::Color::Aquamarine1;
  War::warStateThumbnail = {
"",
"",
"",
"",
"                          _____  _  _____",
"                         (___  \\( )/  ___)",
"                           (___ | | ___)",
"                            /\")`| |'(\"\\",
"                           | |  | |  | |",
"                            \\ \\_| |_/ /",
"                             `._!' _.'",
"                               / .'\\",
"                              | / | |",
"                               \\|/ /",
"                                /.<",
"                               (| |)",
"                                | '",
"                                | |",
"                                `-'"
  };
  warPhase = phase::POST_WAR;
}

void PostWar::handleWarChange(War* war) {
  war->transitionTo(new DisputeSettled());
}

std::string PostWar::getCurrentWarState() {
  return "Currently in Postwar State";
}